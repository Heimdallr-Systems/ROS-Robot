#include <stdint.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>



#define RUNNING_ON RASPI //IMPORTANT: Change this to JETSON when compiling for the jetson

static uint8_t mode;
static uint8_t bits = 8;
static uint32_t speed = 8000000;
static uint16_t delay;
static const char *device = "/dev/spidev0.0";


void raiseError(const char *msg)
{
    perror(msg);
    abort();
}



uint8_t rxBuffer[30];
uint8_t txBuffer[3] = { 0x68, 0x00, 0xF8 };     // First byte sets external clock and internal vref, second byte turns off averaging, third byte scans from AIN0 to AIN14

void readADC(uint16_t adcVals[15])
{
    // uint16_t adcVals[15];
    uint8_t delay = 0;
    int32_t fd;
    uint8_t mode = 3;


    // Open the SPI connection
    fd = open(device, O_RDWR);
    if (fd < 0)
    {
        raiseError("Cannot open SPI device");
    }
    if (ioctl(fd, SPI_IOC_WR_MODE, &mode))
    {
        raiseError("Can't set SPI Mode");
    }
    if (ioctl(fd, SPI_IOC_WR_BITS_PER_WORD, &bits))
    {
        raiseError("Can't sets bits per word");
    }
    if (ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed))
    {
        raiseError("Can't set max speed in hz");
    }

    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long) txBuffer,
        .rx_buf = (unsigned long) rxBuffer,
        .len = 0,
        .delay_usecs = delay,
        .speed_hz = speed,
        .bits_per_word = bits,
    };
    if (ioctl(fd, SPI_IOC_MESSAGE(1), &tr) < 1)
    {
        raiseError("SPI Transaction Failed");
    }

    // tr.len = 30;
    // tr.tx_buf = null

    for (uint8_t i = 0; i < 15; i++)
    {
        adcVals[i] =
            (((uint16_t) rxBuffer[2 * i] << 8) +
             (rxBuffer[2 * i + 1])) >> 2;
    }
    printf("Done Reading\n");
    close(fd);

};

int main()
{
    uint16_t adcVals[15];
    readADC(adcVals);

    for (uint8_t i = 0; i < 15; i++)
    {
        printf("%i\t", adcVals[i]);
    }

    printf("\n");
    printf("Done!");
}
