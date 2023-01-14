/************ I N C L U D E S *************************************************/
#include <p18f4620.h>
#include <delays.h>
#include "Config_FUSES.h"   //Only here
#include "uart.h"
#include "varios.h"

unsigned char alerta[]=" Ingrese letra a-h\r";

void main(void){
   unsigned char val_usart=0;
   MCU_Init();      //Initilization of uC
   UART_Init();    //Initilization of UART
   while(1){
       UART_WriteString(alerta);
       val_usart=UART_ReadByte();
       Delay10KTCYx(100);
       opciones(val_usart);

   }
}
