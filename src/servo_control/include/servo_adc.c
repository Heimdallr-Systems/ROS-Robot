#include "servo_adc.h"
static const char *device = "/dev/spidev0.1";
uint8_t txBuffer[3] = {0x68, 0x20, 0xF0}; // First byte sets external clock and internal vref,
int fd;
int result;
static uint32_t speed = 8000000;
uint32_t rs;






ADC_ERRORS_T readADC(uint16_t adv[15])
{
uint8_t rxBuffer[30];
fd = open(device, O_RDWR);
//printf("FD: %i\n", fd);
ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
ioctl(fd, SPI_IOC_RD_MAX_SPEED_HZ, &rs);
//printf("SPEED:  %i\t%i\n", result,rs);
write(fd, txBuffer, 3);
usleep(200);
read(fd, rxBuffer, 30);
close(fd);

for (uint8_t i = 0; i < 15; i++)
{
    adv[i] = (((uint16_t)rxBuffer[2*i] << 8) + (rxBuffer[2*i+1]));
    adv[i] = (adv[i] & 0xFFF) >> 2;
}
return 0;
}


//============================================//
//		EXAMPLE IMPLEMENTATION 	      //
//============================================//

/*
int main()
{
uint16_t adcVals[15];

for (int i=0; i<15; i++){
adcVals[i]=0;
}

while (1){
readADC(adcVals);

    for (uint8_t i = 0; i < 15; i++)
    {
        printf("%i\t", adcVals[i]);
    }

    printf("\n");
}
    printf("Done!");
    return 0;
}
*/

