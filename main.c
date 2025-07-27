#include "mcc_generated_files/system/clock.h"

#define FCY CLOCK_PeripheralFrequencyGet()

#include <stdio.h>
#include <libpic30.h>
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/adc/adc1.h"
#include "mcc_generated_files/uart/uart1.h"
#include "mcc_generated_files/system/pins.h"
#include "mcc_generated_files/timer/timer_interface.h"

#define LED0 _LATC8
#define LED1 _LATC9
#define LED2 _LATC0
#define LED3 _LATC1
#define LED4 _LATC2
#define LED5 _LATC3
#define LED6 _LATC4
#define LED7 _LATC5
#define LED8 _LATC6
#define LED9 _LATC7

const struct ADC_INTERFACE *adc = &ADC1;
const struct UART_INTERFACE *UartSerial = &UART1_Drv;
const struct TIMER_INTERFACE *timer = &Timer1;

static void TMR1_TimeoutCallback(void)
{
    printf("~~~~~~~~~~~~~~~~~~~~~~~~ 1 SECOND TIMER ELAPSED ~~~~~~~~~~~~~~~~~~~~~~~~\r\n");
}

int main(void)
{
    SYSTEM_Initialize();
    uint16_t volatile adcResult;
    uint16_t volatile newResult = 0;
    
    while(1)
    {
        adc->SoftwareTriggerEnable();
//        __delay_ms(100);
        while (!adc->IsConversionComplete(Channel_AN0));
        
        adcResult = adc->ConversionResultGet(Channel_AN0);
        adcResult /= 100;

        if (newResult != adcResult)
        {
            newResult = adcResult;
            printf("The ADC Result is: %d\r\n", adcResult);
        
            if (adcResult >= 0 && adcResult < 4)
            {
                LED0 = 0;
                LED1 = 0;
                LED2 = 0;
                LED3 = 0;
                LED4 = 0;
                LED5 = 0;
                LED6 = 0;
                LED7 = 0;
                LED8 = 0;
                LED9 = 0;

            }
            else if (adcResult >= 4 && adcResult < 8)
            {
                LED0 = 1;
                LED1 = 0;
                LED2 = 0;
                LED3 = 0;
                LED4 = 0;
                LED5 = 0;
                LED6 = 0;
                LED7 = 0;
                LED8 = 0;
                LED9 = 0;
            }
            else if (adcResult >= 8 && adcResult < 12)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 0;
                LED3 = 0;
                LED4 = 0;
                LED5 = 0;
                LED6 = 0;
                LED7 = 0;
                LED8 = 0;
                LED9 = 0;
            }
            else if (adcResult >= 12 && adcResult < 16)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 1;
                LED3 = 0;
                LED4 = 0;
                LED5 = 0;
                LED6 = 0;
                LED7 = 0;
                LED8 = 0;
                LED9 = 0;
            }
            else if (adcResult >= 16 && adcResult < 20)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                LED4 = 0;
                LED5 = 0;
                LED6 = 0;
                LED7 = 0;
                LED8 = 0;
                LED9 = 0;
            }
            else if (adcResult >= 20 && adcResult < 24)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                LED4 = 1;
                LED5 = 0;
                LED6 = 0;
                LED7 = 0;
                LED8 = 0;
                LED9 = 0;
            }
            else if (adcResult >= 24 && adcResult < 28)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                LED4 = 1;
                LED5 = 1;
                LED6 = 0;
                LED7 = 0;
                LED8 = 0;
                LED9 = 0;
            }
            else if (adcResult >= 28 && adcResult < 32)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                LED4 = 1;
                LED5 = 1;
                LED6 = 1;
                LED7 = 0;
                LED8 = 0;
                LED9 = 0;
            }
            else if (adcResult >= 32 && adcResult < 36)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                LED4 = 1;
                LED5 = 1;
                LED6 = 1;
                LED7 = 1;
                LED8 = 0;
                LED9 = 0;
            }
            else if (adcResult >= 36 && adcResult < 40)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                LED4 = 1;
                LED5 = 1;
                LED6 = 1;
                LED7 = 1;
                LED8 = 1;
                LED9 = 0;
            }
            else if (adcResult >= 40 && adcResult <= 41)
            {
                LED0 = 1;
                LED1 = 1;
                LED2 = 1;
                LED3 = 1;
                LED4 = 1;
                LED5 = 1;
                LED6 = 1;
                LED7 = 1;
                LED8 = 1;
                LED9 = 1;
            }
            else
            {
                LED0 = 1;
                LED1 = 0;
                LED2 = 0;
                LED3 = 0;
                LED4 = 0;
                LED5 = 0;
                LED6 = 0;
                LED7 = 0;
                LED8 = 0;
                LED9 = 1;
            }
        }
    }
}
