Biblioteca HAL para controlar display 16x2 ou 16x4 que utiliza o controlador HD44780.

Microcontrolador utilizando a placa "Blue Pill"com o STM32F103C8

Fonte: https://stm32withoutfear.blogspot.com/2016/10/stm32-lcd-wh16024-hd44780.html

A biblioteca utilizada é formada pelos arquivos: hd44780.c na pasta \src e os arquivos hd44780.h e lcd_cfg.h localizados na pasta \inc.

Copiar esses arquivos para as respectivas pastas do projeto.

Depois é só chamar através da sintaxe:

- /* USER CODE BEGIN Includes */
- #include "hd44780.h"

Lista de funções da biblioteca

A biblioteca pelo seu trabalho e conveniência do usuário, tem várias funções. Não consideraremos funções internas, mas consideremos as funções que precisamos para exibir várias informações.

-- lcdInit - função de inicialização da função de exibição inicial;

Ex:
- /* USER CODE BEGIN 2 */
- lcdInit();

  
-- lcdClrScr - função de limpar a exibição, o cursor em sua posição inicial;

Ex:
- lcdClrScr();

	  
-- lcdReturn - Retorna o cursor para sua posição inicial;

Ex:
- lcdReturn();
	  
	  
-- lcdSetMode - configuração de modo: exibir on / off, cursor pisca on / off, cursor on / off;

Ex:
- lcdSetMode(VIEW_MODE_DispOn_BlkOff_CrsOn);

	
-- lcdGoto - a função define o cursor para um local específico: uma linha, uma coluna;

Ex:
- lcdGoto(LCD_1st_LINE,0); //Posiciona o cursor na primeira linha e primeira coluna
- lcdGoto(LCD_2nd_LINE,0); //Posiciona o cursor na segunda linha e primeira coluna
	  
Obs: Se estiver usando um display 16x4 funcionará os atributos: LCD_3rd_LINE e LCD_4th_LINE


-- lcdPuts - função de saída de linha de texto;

Ex:
- lcdPuts("System Workbench\nFreq MCU "); //Escreve "System Workbench na primeira linha
-                                         //e Freq MCU na segunda linha.
											  

-- lcdPutc - função de saída de um tipo de caractere separado;

Ex:

- /* USER CODE BEGIN 1 */
- unsigned char men1[FONT_HEIGHT] = {0x0e,0x0e,0x04,0x1f,0x04,0x1a,0x01,0x00};
		
- ...
		
- lcdLoadChar(men1,6);
		
- ...
		
- lcdPutc(6);	
		  
- ...

-- lcdLoadChar - função de carregar uma exibição personalizada de caracteres na memória;

Ex:
- /* USER CODE BEGIN 1 */
- unsigned char men1[FONT_HEIGHT] = {0x0e,0x0e,0x04,0x1f,0x04,0x1a,0x01,0x00};
- unsigned char men2[FONT_HEIGHT] = {0x07,0x07,0x0a,0x07,0x02,0x05,0x09,0x00};
		
- ...
		
- lcdLoadChar(men1,6);
- lcdLoadChar(men2,7);
		
- ...
		
- lcdPutc(6);
- lcdPutc(7);
		  
- ...


-- lcdDrawChar - função de desenho na exibição de um caractere personalizado;

Ex:


-- lcdBackSpace - a função de deslocar o cursor para um caractere à esquerda e destruí-lo;

Ex:
- lcdBackSpace();
	
	
-- lcdScroll - a função de deslocar todo o texto em uma coluna na direção certa (esquerda ou direita);

Ex:
- lcdScroll(RIGHT);
      ou
- lcdScroll(LEFT);
		  

-- cursorShift é a função de mover o cursor para a posição direita ou esquerda sem destruir o caractere já representado. Projetado para edição / correção de texto;

Ex:


-- lcdItos - função da saída dos números inteiros da tela;

Ex:
- int t = 123;
- lcdItos(t);		//Será mostrado 123

	  
-- lcdFos - função de exibir um número de tipo float;

Ex:
- float pi = 3.14;
- lcdFtos(pi,2);		//Será mostrado 3.14

	
-- lcdNtos é uma função de produzir um número de números inteiros com um certo número de dígitos. Descargas excessivas são cortadas. Desvantagens em falta são preenchidas com zeros. Para um local fixo na tela;

-- lcdDrawBar - função de desenho do indicador de desempenho;

Antes, o seguinte flag deverá ser habilitado na biblioteca lcd_cfg.h

- //-------------------------------
- // PROGRESS BAR OPTIONS
- //-------------------------------
- #define USE_PROGRESS_BAR			1u				/* 1 (true) or 0 (false) */


Ex:
- for(uint8_t i = 0; i <= PROGRESS_BAR_MAX_LOAD; ++i)
- {
-   lcdGoto(PROGRESS_BAR_LINE, PROGRESS_BAR_WIDTH + 1);
-   lcdNtos((i*100)/PROGRESS_BAR_MAX_LOAD, 3);
-   lcdDrawBar(i);
-   HAL_Delay(100);
- }

	
-- lcdClrBar - indicador de função de limpeza.


--- Bônus ---

- Uma função para escrever no display de maneira bem legal:

/* USER CODE BEGIN Includes */
- #include "hd44780.h"

- ..

- /* Private function prototypes -----------------------------------------------*/
- void imitationPrinting(char *ptr);

- ...

- int main(void)
- {
-	...
	
-	sprintf(str,"STM32F103C8 and");
-	imitationPrinting(str)	
	
-	...
- }

- ...

- /* USER CODE BEGIN 4 */
- void imitationPrinting(char *ptr)
- {

-  lcdSetMode(VIEW_MODE_DispOn_BlkOff_CrsOn);

- while(*ptr != 0)
- {
-  lcdPutc(*ptr++);
-  HAL_Delay(100);
- }

- lcdSetMode(VIEW_MODE_DispOn_BlkOff_CrsOff);
- }
