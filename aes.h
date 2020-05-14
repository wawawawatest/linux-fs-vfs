#ifndef __AES_H
#define __AES_H

#include<stdint.h>


//加密
void EncryptDataToCipherTxt(uint8_t *orign, uint8_t *result, uint16_t length);

//解密
void DecryptCipherTxtToData(uint8_t *orign, uint8_t *result, uint16_t length);

#endif
