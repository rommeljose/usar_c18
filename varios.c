#include <p18f4620.h>
#include "varios.h"
#include "uart.h"

/*********** P O R T   D E F I N I T I O N S **********************************/
#define LED1_TRIS       TRISAbits.TRISA0
#define LED1            LATAbits.LATA0
#define LED2_TRIS       TRISAbits.TRISA1
#define LED2            LATAbits.LATA1
#define LED3_TRIS       TRISEbits.TRISE2
#define LED3            PORTEbits.RE2

/*********** L E D  S T A T U S  M E S S A G E ********************************/
unsigned char mensajeLED1_ON[]=" LED 1 Encendido\r";
unsigned char mensajeLED1_OFF[]=" LED 1 Apagado\r";
unsigned char mensajeLED2_ON[]=" LED 2 Encendido\r";
unsigned char mensajeLED2_OFF[]=" LED 2 Apagado\r";
unsigned char mensajeLED3_ON[]=" LED 3 Encendido\r";
unsigned char mensajeLED3_OFF[]=" LED 3 Apagado\r";
unsigned char mensajeAllLED_ON[]=" LEDs Encendidos\r";
unsigned char mensajeAllLED_OFF[]=" LEDs Apagados\r";


void opciones(unsigned char val_usart){
           switch (val_usart){
           case 'a':
               LED1 = 1;
               UART_WriteString(mensajeLED1_ON);
               break;
           case 'b':
               LED1 = 0;
               UART_WriteString(mensajeLED1_OFF);
               break;
           case 'c':
               LED2 = 1;
               UART_WriteString(mensajeLED2_ON);
               break;
           case 'd':
               LED2 = 0;
               UART_WriteString(mensajeLED2_OFF);
               break;
           case 'e':
               LED3 = 1;
               UART_WriteString(mensajeLED3_ON);
               break;
           case 'f':
               LED3 = 0;
               UART_WriteString(mensajeLED3_OFF);
               break;
           case 'g':
               LED1 = 1;
               LED2 = 1;
               LED3 = 1;
               UART_WriteString(mensajeAllLED_ON);
               break;
           case 'h':
               LED1 = 0;
               LED2 = 0;
               LED3 = 0;
               UART_WriteString(mensajeAllLED_OFF);
               break;
           default:
               LED1 = 1;
               LED2 = 1;
               LED3 = 0;
               break;
       };     
}

/*******************************************************************************
 * Function:        void MCU_Init(void)
 * Description:     Configura opciones del sitema. Velocidad, entras y salidas
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         Oscilador interno = 4MHz, PLL activado, OSC = 16MHz
 ******************************************************************************/
void MCU_Init(void){
    OSCCONbits.IRCF = 0b110;    //Fosc = 4MHz
    OSCTUNEbits.PLLEN = 1;      //PLL enable Fosc = 16MHz
    ADCON1=0xFF;    //Entradas digitales
    LED1_TRIS = 0;  //
    LED2_TRIS = 0;  //LEDs como salidas
    LED3_TRIS = 0;  //
    LED1 = 0;   //
    LED2 = 0;   //Apagamos LEDs
    LED3 = 0;   //
}	