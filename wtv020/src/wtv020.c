/*
 * wtv02.c
 *
 *  Created on: 27 de out de 2018
 *      Author: Eng. Fabricio de Lima Ribeiro
 */
#include <wtv020.h>
#include "stm32f10x.h"

//Inicializa o WTV020
void ini_wtv020(void)
{
   GPIO_SetBits(WTV02_PORT, WTV02_CLOCK);
   GPIO_SetBits(WTV02_PORT, WTV02_RESET);
   Delay_ms(1);
   GPIO_ResetBits(WTV02_PORT, WTV02_RESET);
   Delay_ms(5);
   GPIO_SetBits(WTV02_PORT, WTV02_RESET);
   Delay_ms(300);
}

//ENVIA COMANDO
void enviaComando(int comando)
{
   uint16_t i;

   GPIO_ResetBits(WTV02_PORT, WTV02_CLOCK);
   Delay_us(1950);
   for(i=0x8000; i>0; i>>=1)
   {
	  GPIO_ResetBits(WTV02_PORT, WTV02_CLOCK);
      Delay_us(50);
      if(comando & i)
      {
    	 GPIO_SetBits(WTV02_PORT, WTV02_DATA);
      }
      else
      {
    	 GPIO_ResetBits(WTV02_PORT, WTV02_DATA);
      }
      Delay_us(50);
      GPIO_SetBits(WTV02_PORT, WTV02_CLOCK);
      Delay_us(100);
   }
   Delay_us(1900);
}

//PLAY
void Play(int voiceNumber)
{
   enviaComando(voiceNumber);
}

//STOP
void Stop()
{
   enviaComando(WTV02_STOP);
}
