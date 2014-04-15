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
**   File       : uart.h
**   Author     : Sriharsha
**   Website    : www.zuna.in
**   Email      : helpzuna@gmail.com
**   Description: This is the include file for CORTEX-M3 uart driver (It uses mbed framework)
***/

#ifndef __uart_h__
#define __uart_h__

#include "mbed.h"
#include <stdio.h>            // Standard input/output file used in Serialintwrite (sprintf)

#define mbed  0   // mbed framework
#define cmsis 1   // CMSIS framework for Cortex-M series from NXP
#define no_fw 2   // No High Level Framework

#define HIGH_LEVEL_FRAMEWORK mbed

#define UART_INTERRUPTS
#define UART0_INTERRUPT
#define UART1_INTERRUPT
#define UART2_INTERRUPT
#define UART3_INTERRUPT

#define UART0_EN
#define UART1_EN
#define UART2_EN
#define UART3_EN

#define UART0 0
#define UART1 1
#define UART2 2
#define UART3 3

#define UART0_TX_PIN USBTX
#define UART0_RX_PIN USBRX
#define UART1_TX_PIN p26
#define UART1_RX_PIN p25
#define UART2_TX_PIN 
#define UART2_RX_PIN 
#define UART3_TX_PIN 
#define UART3_RX_PIN 

#define UART_RX_BUFFER_SIZE         128
#define NEW_LINE_INDEX_BUFFER_SIZE  20


// ASCII Code Definitions
#define NUL 0x00                          // Null Character
#define SOH 0x01                          // Start Of Heading
#define STX 0x02                          // Start Of Text
#define ETX 0x03                          // End Of Text
#define EOT 0x04                          // End of Transmission
#define ENQ 0x05                          // Enquiry
#define ACK 0x06                          // Acknowledgement
#define BEL 0x07                          // Bell
#define BS  0x08                          // Back Space
#define TAB 0x09                          // Horizontal TAB
#define LF  0x0A                          // Line Feed (Newline)
#define VT  0x0B                          // Vertical TAB
#define NP  0x0C                          // New Page
#define CR  0x0D                          // Carriage Return
#define SO  0x0E                          // Shift OUT
#define SI  0x0F                          // Shift IN
#define DLE 0x10                          // Data Link Escape
#define DC1 0x11                          // Device Control 1
#define DC2 0x12                          // Device Control 2
#define DC3 0x13                          // Device Control 3
#define DC4 0x14                          // Device Control 4
#define NAK 0x15                          // Negative Acknowledgement
#define SYN 0x16                          // Synchronous Idle
#define ETB 0x17                          // End of Trans. Block
#define CAN 0x18                          // Cancel
#define EM  0x19                          // End of Medium
#define SUB 0x1A                          // Substitute
#define ESC 0x1B                          // Escape
#define FS  0x1C                          // File Seperator
#define GS  0x1D                          // Group Seperator
#define RS  0x1E                          // Record Seperator
#define US  0x1F                          // Unit Seperator

#define CHAR_NULL  '\0'                   // Null charactor


// Radix for Serial Integer Print
#define HEX 16
#define DEC 10
#define OCT 8
#define BIN 2



/***************** Prototypes ****************************/
extern void           Serialbegin(unsigned char,unsigned long);
extern unsigned char  Serialavailable(unsigned char);
extern void           Serialwrite(unsigned char,char);
extern void           Serialprint(unsigned char,char*);
extern unsigned char  Serialread(unsigned char);
extern void           SerialIntWrite(unsigned char,signed int);
extern void           SerialDoubleWrite(unsigned char,double);

#if defined (UART_INTERRUPTS)
extern void           setSerialinterrupt(unsigned char);
#if defined (UART0_INTERRUPT)
extern void           UART0_ISR(void);
#endif
#if defined (UART1_INTERRUPT)
extern void           UART1_ISR(void);
#endif
#if defined (UART2_INTERRUPT)
extern void           UART2_ISR(void);
#endif
#if defined (UART3_INTERRUPT)
extern void           UART3_ISR(void);
#endif
#endif

#ifdef UART_INTERRUPTS
struct UART_READ_BUFFER
{
 volatile unsigned char          uartNewLineFlag;
 volatile char                   uartReadBuffer[UART_RX_BUFFER_SIZE];
 volatile unsigned int           uartReadCount;
 volatile unsigned char          uartNewLineCount;
 volatile unsigned char          uartNewLineIndexes[NEW_LINE_INDEX_BUFFER_SIZE];
};

#endif

#endif // Header File

