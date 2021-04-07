#include <stdint.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <gpiod.h>
// #include <gpiod.h>

#ifndef SERVO_ADC_H

#define SERVO_ADC_H

// Pin 15 of the header is mapped as 194 in Linux (I think it is the SODIMM pin)
#define ADC_EOC_PIN 194


typedef enum error_e {
    NO_ERROR,
    ADC_OPEN_ERROR,
    ADC_MODE_ERROR,
    ADC_BPW_ERROR,
    ADC_SPEED_ERROR,
    ADC_WRITE_ERROR,
    ADC_READ_ERROR,
    ADC_CLOSE_ERROR,
    ADC_GPIO_OPEN_ERROR,
    ADC_GPIO_MODE_ERROR,
    ADC_GPIO_LINE_ERROR,
    ADC_GPIO_REQUST_ERROR,
    ADC_GPIO_WAIT_ERROR,
    ADC_GPIO_CLOSE_ERROR,
    ADC_GPIO_TIMEOUT
} ADC_ERRORS_T;

struct gpiod_chip *chip;
struct gpiod_line *line;

typedef int32_t ADC_SPI_T;

typedef struct gpio_s {
    struct gpiod_chip *chip;
    struct gpiod_line *line;
} ADC_GPIO_T;

/**
 * @brief Initialize the connection to the ADC
 *  This function initializes the SPI connection, and the GPIO pin used for EOC
 * 
 * @param adc_spi: Pointer to a variable that will store the SPI file descriptor
 * @param adc_gpio: Pointer to a variable that stores the information needed for the GPIO connection
 * @returns Error code from running the function, or 0 if successful
 */
ADC_ERRORS_T setupADC(ADC_SPI_T *adc_spi, ADC_GPIO_T *adc_gpio);

/**
 * @brief Read the data from the ADC
 *  This function readsd channels 0 through 14 on the adc
 * 
 * @param adc_spi: Pointer to a variable that will store the SPI file descriptor
 * @param adc_gpio: Pointer to a variable that stores the information needed for the GPIO connection
 * @param adcVals: 15 element array that the raw ADC Values are stored in.
 * @returns Error code from running the function, or 0 if successful
 */
ADC_ERRORS_T readADC(ADC_SPI_T *adc_spi, ADC_GPIO_T *adc_gpio, uint16_t adcVals[15]);
ADC_ERRORS_T closeADC(ADC_SPI_T *adc_spi, ADC_GPIO_T *adc_gpio);

/**
 * @brief Close connection to the ADC
 *  This closes the SPI bus and the GPIO pin that the ADC uses
 * 
 * @param adc_spi: Pointer to a variable that will store the SPI file descriptor
 * @param adc_gpio: Pointer to a variable that stores the information needed for the GPIO connection
 * @returns Error code from running the function, or 0 if successful
 */
#endif