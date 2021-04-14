#include "servo_adc.h"


//============================================//
//		EXAMPLE IMPLEMENTATION 	      //
//============================================//


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


