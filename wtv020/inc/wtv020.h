/*
 * Esta biblioteca comanda o módulo WTV02 no modo SPL
 *
 * wtv020.h
 *
 *  Created on: 27 de out de 2018
 *      Author: Eng. Fabricio de Lima Ribeiro
 *
 *  no arquivo main.c incluir os arquivos na sequencia:
    #include "delays.h"
    #include "wtv020.h"
 */
//Dependências: delays.h

#ifndef WTV020_H_
#define WTV020_H_

//definição dos pinos de controle
#define	WTV020_RESET GPIO_Pin_0 //PA0-RESET
#define	WTV020_CLOCK GPIO_Pin_1 //PA1-CLOCK
#define WTV020_DATA  GPIO_Pin_2 //PA2-DATA
#define WTV020_PORT  GPIOA

//definição do comando stop e volume
#define WTV020_STOP   0xFFFF
#define WTV020_VOLUME 0xFFF5; //configura o volume 5

//funções
extern void Delay_ms(const int msec); //delay ms
void ini_wtv020(void); //inicializa o wtv020
void enviaComando(int comando); //envia comando
void Play(int voiceNumber); //toca a música desejada
void Stop(); //para a música

#endif /* WTV020_H_ */
