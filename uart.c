//*********** I N C L U D E S *************************************************/
#include <p18f4620.h>
#include "uart.h"

/*******************************************************************************
 * Function:        void UART_Init(void)
 * Description:     Initialization of UART
 * Precondition:    None
 * Parameters:      None
 * Return Values:   None
 * Remarks:         1. Enable Transmitter and select High Baud Rate in TXSTA
 *                  2. Select a value in SPGRB register to generate 9600 baud rate
 *                  3. Enable Serial port in RCSTA register
 *                  4. Enable continuous reception in RCSTA
 ******************************************************************************/
void UART_Init(void){
    //Configure RC6/TX/CK and RC7/RX/DT as a UART
    UART_RX_TRIS = 1;
    UART_TX_TRIS = 0;
    UART_TX_STATUS = 0;     // Reset TXSTA
    UART_RX_STATUS = 0;     // Reset RCSTA
    UART_TX_STATUS = 0x20;  // Load TXSTA from TxConUser selected
    SPBRG = BAUD_RATE;      // Write baudrate to SPBRG
    UART_RX_STATUS = 0x90;
    BAUDCON = BAUD_CONTROL;
}

/*******************************************************************************
 * Function:        unsigned char UART_ReadByte(void)
 * Description:     Wait till a byte received from terminal
 * Precondition:    None
 * Parameters:      None
 * Return Values:   Return a byte received from UART
 * Remarks:         None
 ******************************************************************************/
unsigned char UART_ReadByte(void){
    unsigned char recv_data;
    while(!PIR1bits.RCIF);
        recv_data = RCREG;
	PIR1bits.RCIF = 0;
    return (recv_data);
}

/*******************************************************************************
 * Function:        void UART_WriteByte (unsigned char data_byte)
 * Description:     Transmits a byte to terminal through UART
 * Precondition:    None
 * Parameters:      unsigned char send_data = Byte to transmit
 * Return Values:   None
 * Remarks:         None
 ******************************************************************************/
void UART_WriteByte (unsigned char data_byte){
    TXREG = data_byte;          // Also transmit USART status value
	while (!TXSTAbits.TRMT);    // wait here transmission to complete.
}

/*******************************************************************************
 * Function:        void UART_WriteString (unsigned char *mess)
 * Description:     Sends the string to terminal till it finds NULL character.
 * Precondition:    None
 * Parameters:      unsigned char *data_string = Pointer to display message
 * Return Values:   None
 * Remarks:         None
 ******************************************************************************/
void UART_WriteString (unsigned char *data_string){
    while(*data_string != '\0'){
        UART_WriteByte(*data_string++);
    }
}