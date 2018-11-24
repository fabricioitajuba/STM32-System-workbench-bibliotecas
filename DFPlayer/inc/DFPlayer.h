/*
 * DFPlayer.h
 *
 *  Created on: 22 de nov de 2018
 *      Author: Fabricio
 *      Versão: 1.1 - Ainda não acabado e testado
 *      obs:
 */

#ifndef DFPLAYER_H_
#define DFPLAYER_H_

//Definições da Inicializaçãoo
#define INI_U_DISK 	0x01
#define INI_TF_CARD	0x02
#define INI_PC		0x04
#define INI_FLASH	0x08
#define INI_U_DISK	0x03

//Tipo de fonte da música
#define UT 		0
#define TF 		1
#define AUX 	2
#define SLEEP 	3
#define FLASH 	4

//Tipos de equalização
#define NORMAL	0
#define POP		1
#define ROCK	2
#define JAZZ	3
#define CLASSIC	4
#define BASE	5

//Modo de playback
#define REPEAT			0
#define FOLDER_REPEAT	1
#define SINGLE_REPEAT	2
#define RANDOM			3

// USART routines ** specific to USART1
void SetupUSART(void);
void USART_PutChar(char c);
void USART_PutStr(char *str);

void USART_PutHexByte(unsigned char byte);
void USART_PutStrHex(char *str);

void send_comand_DFPlayer(uint8_t cmd, uint8_t para1, uint8_t para2);
void ini_DFPlayer(uint8_t ini);
void specify_playback_source(uint8_t source);
void specify_eq(uint8_t eq);
void specify_playback_mode(uint8_t mode);
void next(void);
void previous(void);
void play(uint8_t num_H, uint8_t num_L);
void pause(void);
void volume(uint8_t vol);
void Loop(void);

#endif /* DFPLAYER_H_ */
