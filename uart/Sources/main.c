/* ###################################################################
**     Filename    : main.c
**     Project     : uart
**     Processor   : MKL43Z256VLH4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-10-03, 12:08, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "clockMan1.h"
#include "pin_init.h"
#include "osa1.h"
#include "uartCom1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */
const uint8_t buffStart[]   = "\r\n++++++++++++++++ UART Send/Receive Blocking Example Start +++++++++++++++++\r\n";
const uint8_t bufferData1[] = "\r\nType characters from keyboard, the board will receive and then echo them to terminal screen\r\n";


/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	uint8_t rxChar=0;
	uint8_t byteCountBuff=0;
	uart_state_t uartState; // provides memory for the driver state structure

	uart_user_config_t uartConfig = {
		.baudRate=9600,
		.bitCountPerChar=kUart8BitsPerChar,
		.parityMode=kUartParityDisabled,
		.stopBitCount=kUartOneStopBit,

	};

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  //maybe:
  hardware_init();
  OSA_Init();

  /* Write your code here */
  /* For example: for(;;) { } */
  // Initialize the uart module with base address and config structure
  UART_DRV_Init(2,&uartState,&uartConfig);//

  //Inform to start blocking example
  byteCountBuff=sizeof(buffStart);
  UART_DRV_SendDataBlocking(2,buffStart,byteCountBuff,1000u);
  //Inform User what to do
  byteCountBuff=sizeof(bufferData1);
  UART_DRV_SendDataBlocking(2,bufferData1,byteCountBuff,1000u);
  //Send/receive blocking function
  while(true){
	  //Wait to receive input data
	  if(kStatus_UART_Success==UART_DRV_ReceiveDataBlocking(2,&rxChar,1u,OSA_WAIT_FOREVER)){
		  //echo received character
		  UART_DRV_SendDataBlocking(2,&rxChar,1u,1000u);
	  }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
