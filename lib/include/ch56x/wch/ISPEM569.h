/********************************** (C) COPYRIGHT *******************************
* File Name          : ISPEM569.h
* Author             : WCH
* Version            : V1.0
* Date               : 2024/01/12
* Description        : for the chip only USER code area, no BOOT
*********************************************************************************
* Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
* Attention: This software (modified or not) and binary are used for 
* microcontroller manufactured by Nanjing Qinheng Microelectronics.
*******************************************************************************/

/* V1.1 FlashROM library for BOOT */
/* 1. for the chip only USER code area, no BOOT */
/* 2. for the target in BOOT area on the chip divided into USER code area and BOOT area */
/* It is used when there is no boot area, only user code area, and can be called in user code (IAP, erase itself).
   Or for a chip with a user code area and a boot area, the operation target is the case of the boot code area, which can only be called in the boot code (update itself) */

/* Flash-ROM feature:
     for store program code, support block erasing, dword and page writing, dword verifying, unit for Length is byte,
     minimal quantity for write or verify is one dword (4-bytes),
     256 bytes/page for writing, FLASH_ROM_WRITE support one dword or more dword writing, but multiple of 256 is the best,
     4KB (4096 bytes) bytes/block for erasing, so multiple of 4096 is the best */

/* Data-Flash(EEPROM) feature:
     for store data, support block erasing, byte and page writing, byte reading,
     minimal quantity for write or read is one byte,
     256 bytes/page for writing, EEPROM_WRITE support one byte or more byte writing, but multiple of 256 is the best,
     4KB (4096 bytes) bytes/block for erasing, so multiple of 4096 is the best */

#ifndef EEPROM_PAGE_SIZE
#define EEPROM_PAGE_SIZE    256                       // Flash-ROM & Data-Flash page size for writing
#define EEPROM_BLOCK_SIZE   4096                      // Flash-ROM & Data-Flash block size for erasing
#define EEPROM_MIN_ER_SIZE  EEPROM_BLOCK_SIZE         // Flash-ROM & Data-Flash minimal size for erasing
#define EEPROM_MIN_WR_SIZE  1                         // Data-Flash minimal size for writing
#define EEPROM_MAX_SIZE     0x8000                    // Data-Flash maximum size, 32KB
#endif
#ifndef FLASH_MIN_WR_SIZE
#define FLASH_MIN_WR_SIZE   4                         // Flash-ROM minimal size for writing
#endif
#ifndef FLASH_ROM_MAX_SIZE
#define FLASH_ROM_MAX_SIZE  0x070000                  // Flash-ROM maximum program size, 448KB
#endif

extern void GET_UNIQUE_ID( void *Buffer );  // get 64 bit unique ID

extern void FLASH_ROM_PWR_DOWN( void );  // power-down FlashROM

extern void FLASH_ROM_PWR_UP( void );  // power-up FlashROM

extern void EEPROM_READ( uint32_t StartAddr, void *Buffer, uint32_t Length );  // read Data-Flash data block

extern uint8_t EEPROM_ERASE( uint32_t StartAddr, uint32_t Length );  // erase Data-Flash block, minimal block is 4KB, return 0 if success

extern uint8_t EEPROM_WRITE( uint32_t StartAddr, void *Buffer, uint32_t Length );  // write Data-Flash data block, return 0 if success

extern uint8_t FLASH_ROMA_ERASE( uint32_t StartAddr, uint32_t Length );  // erase FlashROM block, minimal block is 4KB, return 0 if success

extern uint8_t FLASH_ROMA_WRITE( uint32_t StartAddr, void *Buffer, uint32_t Length );  // write FlashROM data block, minimal block is dword, return 0 if success

extern uint32_t FLASH_ROMA_VERIFY( uint32_t StartAddr, void *Buffer, uint32_t Length );  // verify FlashROM data block, minimal block is dword, return 0 if success

extern uint8_t FLASH_ROMA_READ( uint32_t StartAddr, void *Buffer, uint32_t Length );  // read FlashROM data block, minimal block is dword, return 0 if success

extern void GET_FLASH_ID( void *Buffer );  // get 128 bit FLASH ID
