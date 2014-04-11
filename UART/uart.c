/***************************************************************************************************************
    This file is part of Library for CORTEX-M3.

    Library for CORTEX-M3 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Library for CORTEX-M3 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Library for CORTEX-M3.  If not, see <http://www.gnu.org/licenses/>.
/**************************************************************************************************************/

/***
**   File       : uart.c
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the uart driver for CORTEX-M3 family MCU's (It uses mbed framework)
***/

#include "uart.h"
#include "mbed.h"


// Serial Objects
#if (defined) UART0_EN
Serial Serial0(UART0_TX_PIN,UART0_RX_PIN); // Tx,Rx
#endif
#if (defined) UART1_EN
Serial Serial1(UART1_TX_PIN,UART1_RX_PIN); // Tx,Rx
#endif
#if (defined) UART2_EN
Serial Serial2(UART2_TX_PIN,UART2_RX_PIN); // Tx,Rx
#endif
#if (defined) UART3_EN
Serial Serial3(UART3_TX_PIN,UART3_RX_PIN); // Tx,Rx
#endif

#if defined (UART_INTERRUPTS)
// Structure instances
#if defined (UART0_INTERRUPT)
volatile struct UART_READ_BUFFER UART0RX;
#endif
#if defined (UART1_INTERRUPT)
volatile struct UART_READ_BUFFER UART1RX;
#endif
#if defined (UART2_INTERRUPT)
volatile struct UART_READ_BUFFER UART2RX;
#endif
#if defined (UART3_INTERRUPT)
volatile struct UART_READ_BUFFER UART3RX;
#endif
#else
#warning "UART Interrupts are disabled"
#endif


/*** Function    : Serialbegin
**   Parameters  : unsigned char(UART Port Number (i.e UART0,UART1,UART2)),unsigned long (Standard BaudRate)
**   Return      : None
**   Description : It will Set the baud rate for serial communication
**/
void Serialbegin(unsigned char uartNo,unsigned long baudRate)
{
#ifdef UART0_EN
if(uatNo == UART0)
Serial0.baud(baudRate);
#endif
#ifdef UART1_EN
if(uatNo == UART1)
Serial1.baud(baudRate);
#endif
#ifdef UART2_EN
if(uatNo == UART2)
Serial2.baud(baudRate);
#endif
#ifdef UART3_EN
if(uatNo == UART3)
Serial3.baud(baudRate);
#endif
}

/*** Function    : Serialavailable
**   Parameters  : None
**   Return      : __bit (If byte is available in receive buffer returns 1, else returns 0)
**   Description : It will give the whether Receiver is available or not
**/
unsigned char Serialavailable(unsigned char uartNo)
{
#ifdef UART0_EN
return Serial0.readable();
#endif
#ifdef UART1_EN
return Serial1.readable();
#endif
#ifdef UART2_EN
return Serial2.readable();
#endif
#ifdef UART3_EN
return Serial3.readable();
#endif
}


/*** Function    : Serialwrite
**   Parameters  : char (Single character that will send to UART)
**   Return      : None
**   Description : It will write single character to UART
**/
void Serialwrite(unsigned char uartNo,char Byte)
{
#ifdef UART0_EN
if(uatNo == UART0)
Serial0.putc(Byte);
#endif
#ifdef UART1_EN
if(uatNo == UART1)
Serial1.putc(Byte);
#endif
#ifdef UART2_EN
if(uatNo == UART2)
Serial2.putc(Byte);
#endif
#ifdef UART3_EN
if(uatNo == UART3)
Serial3.putc(Byte);
#endif
}

/*** Function    : Serialread
**   Parameters  : None
**   Return      : unsigned char
**   Description : It will read single byte from uart
**/
volatile char Serialread(unsigned char uartNo)
{
#ifdef UART0_EN
if(uatNo == UART0)
return Serial0.getc();
#endif
#ifdef UART1_EN
if(uatNo == UART1)
return Serial1.getc();
#endif
#ifdef UART2_EN
if(uatNo == UART2)
return Serial2.getc();
#endif
#ifdef UART3_EN
if(uatNo == UART3)
return Serial3.getc();
#endif
}

/*** Function    : Serialprint
**   Parameters  : unsigned char *
**   Return      : None
**   Description : It will send the string to UART
**/
void Serialprint(unsigned char uartNo,char *sPtr)
{
#ifdef UART0_EN
if(uatNo == UART0)
Serial0.printf(sPtr);
#endif
#ifdef UART1_EN
if(uatNo == UART1)
Serial1.printf(sPtr);
#endif
#ifdef UART2_EN
if(uatNo == UART2)
Serial2.printf(sPtr);
#endif
#ifdef UART3_EN
if(uatNo == UART3)
Serial3.printf(sPtr);
#endif
}


/*** Function    : SerialIntWrite
**   Parameters  : unsigned char *
**   Return      : None
**   Description : It will write integer on uart
**/
void SerialIntWrite(signed int num)
{
#ifdef UART0_EN
if(uatNo == UART0)
Serial0.printf("%d",num);
#endif
#ifdef UART1_EN
if(uatNo == UART1)
Serial1.printf("%d",num);
#endif
#ifdef UART2_EN
if(uatNo == UART2)
Serial2.printf("%d",num);
#endif
#ifdef UART3_EN
if(uatNo == UART3)
Serial3.printf("%d",num);
#endif
}


/*** Function    : SerialDoubleWrite
**   Parameters  : double,unsigned char 
**   Return      : None
**   Description : It will write double on uart
**/
void SerialDoubleWrite(unsigned char uartNo,double __f)
{
#ifdef UART0_EN
if(uatNo == UART0)
Serial0.printf("%f",__f);
#endif
#ifdef UART1_EN
if(uatNo == UART1)
Serial1.printf("%f",__f);
#endif
#ifdef UART2_EN
if(uatNo == UART2)
Serial2.printf("%f",__f);
#endif
#ifdef UART3_EN
if(uatNo == UART3)
Serial3.printf("%f",__f);
#endif
}

#if defined (UART_INTERRUPTS)

/*** Function    : setSerialinterrupt
**   Parameters  : None
**   Return      : None
**   Description : It sets the Serial Interrupt
**/
 void setSerialinterrupt(unsigned char uartNo)
 {
RFIDReader.attach(&SerialRecvInterrupt, RFIDReader.RxIrq);    // Recv interrupt handler
#ifdef UART0_EN
if(uatNo == UART0)
Serial0.attach(&UART0_ISR, Serial0.RxIrq);
#endif
#ifdef UART1_EN
if(uatNo == UART1)
Serial0.attach(&UART1_ISR, Serial1.RxIrq);
#endif
#ifdef UART2_EN
if(uatNo == UART2)
Serial0.attach(&UART2_ISR, Serial2.RxIrq);
#endif
#ifdef UART3_EN
if(uatNo == UART3)
Serial0.attach(&UART3_ISR, Serial3.RxIrq);
#endif
 }

/*** Function    : UART0 Interrupt Handler
**   Parameters  : None
**   Return      : None
**   Description : It is ISR for UART Receive (It will trigger if any byte is received)
**/
#if defined (UART0_INTERRUPT)
void UART0_ISR(void)
{
char temp = Serial0.getc();
UART0RX->uartReadBuffer[UART0RX->uartReadCount++] = temp;
if(temp  == LF)
{
UART0RX->uartNewLineIndexes[UART0RX->uartNewLineCount] = UART0RX->uartReadCount;
UART0RX->uartNewLineCount++;
UART0RX->uartNewLineFlag = 1;
}
#endif

/*** Function    : UART0 Interrupt Handler
**   Parameters  : None
**   Return      : None
**   Description : It is ISR for UART Receive (It will trigger if any byte is received)
**/
#if defined (UART1_INTERRUPT)
void UART1_ISR(void)
{
char temp = Serial1.getc();
UART1RX->uartReadBuffer[UART1RX->uartReadCount++] = temp;
if(temp  == LF)
{
UART1RX->uartNewLineIndexes[UART1RX->uartNewLineCount] = UART1RX->uartReadCount;
UART1RX->uartNewLineCount++;
UART1RX->uartNewLineFlag = 1;
}
}
#endif

/*** Function    : UART0 Interrupt Handler
**   Parameters  : None
**   Return      : None
**   Description : It is ISR for UART Receive (It will trigger if any byte is received)
**/
#if defined (UART2_INTERRUPT)
void UART2_ISR(void)
{
char temp = Serial2.getc();
UART2RX->uartReadBuffer[UART2RX->uartReadCount++] = temp;
if(temp  == LF)
{
UART2RX->uartNewLineIndexes[UART2RX->uartNewLineCount] = UART2RX->uartReadCount;
UART2RX->uartNewLineCount++;
UART2RX->uartNewLineFlag = 1;
}
#endif

/*** Function    : UART0 Interrupt Handler
**   Parameters  : None
**   Return      : None
**   Description : It is ISR for UART Receive (It will trigger if any byte is received)
**/
#if defined (UART3_INTERRUPT)
void UART3_ISR(void)
{
char temp = Serial3.getc();
UART3RX->uartReadBuffer[UART3RX->uartReadCount++] = temp;
if(temp  == LF)
{
UART3RX->uartNewLineIndexes[UART3RX->uartNewLineCount] = UART2RX->uartReadCount;
UART3RX->uartNewLineCount++;
UART3RX->uartNewLineFlag = 1;
}
#endif

/*** Function    : Serialflush
**   Parameters  : None
**   Return      : None
**   Description : It clears the UART buffer,Index Buffer and Flags
**/
void Serialflush(unsigned char uartNo)
{

}


 

#endif

/************************* EOF **************************************/



