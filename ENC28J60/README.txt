Configurada para utilizar o STM32F103C8

O arquivo "main.c" é um exemplo.

Configuração dos pinos:

System Core -> SYS -> Debug: Serial Wire
PA13 - SYS_JTMS-SWDIO
PA14 - SYS_JTMS-SWCLK

System Core -> RCC -> Hight Speed Clock (HSE): Crystal/Ceramic Resonator
PD0 - RCC_OSC_IN
PD1 - RCC_OSC_OUT

PC13 - GPIPO_Output - LED

Clock Configuration
HCLK (MHz) = 72 MHz

Connectivity -> SPI1 
SPI1 Mode and Configuration:
Mode: Full-Duplex Master

Parameter Settings:
Prescaler: 64

PA4 - GPIPO_Output - SPI1_CS
PA5 - SPI1_SCK
PA6 - SPI1_MISO
PA7 - SPI1_MOSI

