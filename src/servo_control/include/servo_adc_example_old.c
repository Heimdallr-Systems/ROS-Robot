#include <stdint.h>

#include <printf.h>
#include "servo_adc.h"

ADC_SPI_T adcDevice;
ADC_GPIO_T adcGPIO;
uint16_t adcVals[15];



int main()
{
    if (setupADC(&adcDevice, &adcGPIO))
    {
        printf("ADC Init Error\n");
        return -1;
    }
    if (readADC(&adcDevice, &adcGPIO, adcVals))
    {
        printf("ADC Read Error\n");
        return -1;
    }
//    if (closeADC(&adcDevice, &adcGPIO))
  //  {
   //     printf("ADC Close Error\n");
    //    return -1;
    //}

    for (uint8_t i = 0; i < 15; i++)
    {
        printf("%i\t", adcVals[i]);
    }

    printf("\n");
    printf("Done!");
    return 0;
}

