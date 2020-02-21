Biblioteca para trabalhar com a memória flash

Exemplo de uso com o STM32F103C8:

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "memory.h"
/* USER CODE END Includes */

...

	MemoryMap map;

	static const uint32_t memoryMapSize = sizeof(map) / sizeof(uint32_t);

	map.data0 = 1;
	map.data1 = 2;
	map.data2 = 3;

	/*Store map to flash*/
	MemMap_WriteAllEntriesToFlash(&map, memoryMapSize);
	/*Change a value to see if the store and restore was correct*/
	map.data1 = 9;
	/*Read map from flash*/
	MemMap_ReadAllEntriesFromFlash(&map, memoryMapSize);
	/*map.data1 is now 2 again, as we restored it from the flash*/
