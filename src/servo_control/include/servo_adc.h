#ifdef __cplusplus
extern "C"
{
#endif


#ifndef SERVO_ADC_H
#define SERVO_ADC_H

#include <stdint.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
//#include <gpiod.h>
#include <time.h>




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


/**
 * @brief Read the data from the ADC
 *  This function readsd channels 0 through 14 on the adc
 * 
 * @param adc_spi: Pointer to a variable that will store the SPI file descriptor
 * @param adc_gpio: Pointer to a variable that stores the information needed for the GPIO connection
 * @param adcVals: 15 element array that the raw ADC Values are stored in.
 * @returns Error code from running the function, or 0 if successful
 */
ADC_ERRORS_T readADC(uint16_t adv[15]);

#endif
#ifdef __cplusplus
}
#endif
