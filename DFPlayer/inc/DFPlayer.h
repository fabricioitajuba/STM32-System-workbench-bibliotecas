/*
 * DFPlayer.h
 *
 *  Created on: 22 de nov de 2018
 *      Author: Fabricio
 *      Vers�o: 1.0 - Ainda n�o acabado e testado
 *      obs: o c�lculo do checksum ainda n�o est� correto.
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
