
#include "servo_adc.h"

static uint8_t bits = 8;
static uint32_t speed = 8000000;
static const char *device = "/dev/spidev0.1";
static uint8_t mode = SPI_MODE_3;

uint8_t rxBuffer[30];
uint8_t txBuffer[3] = {0x68, 0x00, 0xF8}; // First byte sets external clock and internal vref, second byte turns off averaging, third byte scans from AIN0 to AIN14
uint8_t txBufferEmpty[0] = {};

ADC_ERRORS_T setupADC(ADC_SPI_T *adc_spi, ADC_GPIO_T *adc_gpio)
{

    // Open the SPI device
    *adc_spi = open(device, O_RDWR);
    if (*adc_spi < 0)
    {
        return ADC_OPEN_ERROR;
    }

    // Set the SPI mode
    if (ioctl(*adc_spi, SPI_IOC_WR_MODE, &mode))
    {
        return ADC_MODE_ERROR;
    }

    // Set the number of bits per word for SPI
    if (ioctl(*adc_spi, SPI_IOC_WR_BITS_PER_WORD, &bits))
    {
        return ADC_BPW_ERROR;
    }

    // Set the SPI Bus speed
    if (ioctl(*adc_spi, SPI_IOC_WR_MAX_SPEED_HZ, &speed))
    {
        return ADC_SPEED_ERROR;
    }

    // Open the GPIO Chip the pin s on
    adc_gpio->chip = gpiod_chip_open("/dev/gpiochip0");
    if (!adc_gpio->chip)
    {
        return ADC_GPIO_OPEN_ERROR;
    }

    // Get the correct GPIO pin
    adc_gpio->line = gpiod_chip_get_line(adc_gpio->chip, ADC_EOC_PIN);
    if (!adc_gpio->line)
    {
        gpiod_chip_close(adc_gpio->chip);
        return ADC_GPIO_LINE_ERROR;
    }

    // Set the GPIO pin to detect falling edge events (pin goes from high to low)
    if (gpiod_line_request_falling_edge_events(adc_gpio->line, "ADC_EOC_WAIT"))
    {
        gpiod_chip_close(adc_gpio->chip);
        return ADC_GPIO_REQUST_ERROR;
    }

    return NO_ERROR;
}

ADC_ERRORS_T closeADC(ADC_SPI_T *adc_spi, ADC_GPIO_T *adc_gpio)
{
    // Close the SPI connection
    if (close(*adc_spi))
    {
        return ADC_CLOSE_ERROR;
    }
    return NO_ERROR;

    // Close the GPIO pin
    gpiod_chip_close(adc_gpio->chip);
}

ADC_ERRORS_T readADC(ADC_SPI_T *adc_spi, ADC_GPIO_T *adc_gpio, uint16_t adcVals[15])
{
    int waitStatus;
    // uint16_t adcVals[15];
    uint8_t delay = 0;

    struct spi_ioc_transfer adcTxCMD = {
        .tx_buf = (unsigned long)txBuffer,
        // .rx_buf = (unsigned long)rxBuffer,
        .rx_buf = NULL,
        .len = 3,
        .delay_usecs = delay,
        .speed_hz = speed,
        .bits_per_word = bits,
    };
    if (ioctl(*adc_spi, SPI_IOC_MESSAGE(1), &adcTxCMD) < 1)
    {
        return ADC_WRITE_ERROR;
    }

    switch (gpiod_line_event_wait(adc_gpio->line, NULL))
    {
    case 0:
        return ADC_GPIO_TIMEOUT;
        break;
    case -1:
        return ADC_GPIO_WAIT_ERROR;
        break;
    default:
        break;
    }


    struct spi_ioc_transfer adcRxCMD = {
        // .tx_buf = (unsigned long)txBuffer,
        .tx_buf = (unsigned long)txBuffer,
        .rx_buf = (unsigned long)rxBuffer,
        .len = 30,
        .delay_usecs = delay,
        .speed_hz = speed,
        .bits_per_word = bits,
    };
    if (ioctl(*adc_spi, SPI_IOC_MESSAGE(1), &adcRxCMD) < 1)
    {
        return ADC_READ_ERROR;
    }

    // tr.len = 30;
    // tr.tx_buf = null
    for (uint8_t i = 0; i < 15; i++)
    {
        adcVals[i] =
            (((uint16_t)rxBuffer[2 * i] << 8) +
             (rxBuffer[2 * i + 1])) >>
            2;
    }
    printf("Done Reading\n");
    return NO_ERROR;
};