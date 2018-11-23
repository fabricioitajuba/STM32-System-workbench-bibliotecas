/*
 * DFPlayer.h
 *
 *  Created on: 22 de nov de 2018
 *      Author: Fabricio
 *      Versão: 1.0 - Ainda não acabado e testado
 *      obs: o cálculo do checksum ainda não está correto.
 */

#ifndef DFPLAYER_H_
#define DFPLAYER_H_

#define DEBUG_ON

//#include <stdlib.h>
//#include <stdbool.h>
//#include <stdint.h>

// USART routines ** specific to USART1
void SetupUSART(void);
void USART_PutChar(char c);
void USART_PutStr(char *str);

void USART_PutHexByte(unsigned char byte);
void USART_PutStrHex(char *str);

void send_comand_DFPlayer(uint8_t cmd, uint8_t para1, uint8_t para2);
void play(void);
void pause(void);
void volume(uint8_t vol);
void Loop(void);

#endif /* DFPLAYER_H_ */
