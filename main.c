#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
uint32_t crc16Mask = 0x0000FFFF;
uint32_t crc24Mask = 0x00FFFFFF;
uint32_t crc32Mask = 0xFFFFFFFF;
uint32_t crc16 = 0x1021;
uint32_t crctable16[256]={0};
//uint32_t crc24 = 0x5D6DCB;
//uint32_t crc24 = 0x864CFB;
uint32_t crc24 = 0x800063;
uint32_t crctable24[256]={0};
uint32_t crc32 = 0x4C11DB7;
uint32_t crctable32[256]={0};

void xCrc16()
{
    uint32_t i,j;
    uint32_t curByte;
    for(i=0;i<256;i++){
        curByte = i << 8;
        for(j=0;j<8;j++){
            if((curByte&0x8000)!=0){
                curByte <<= 1;
                curByte ^= crc16;
            }else{
                curByte <<= 1;
            }
        }
        crctable16[i] = curByte;
    }
}
void xCrc24()
{
    uint32_t i,j;
    uint32_t curByte;
    for(i=0;i<256;i++){
        curByte = i << 16;
        for(j=0;j<8;j++){
            if((curByte&0x800000)!=0){
                curByte <<= 1;
                curByte ^= crc24;
            }else{
                curByte <<= 1;
            }
        }
        crctable24[i] = curByte;
    }
}
void xCrc32()
{
    uint32_t i,j;
    uint32_t curByte;
    for(i=0;i<256;i++){
        curByte = i << 24;
        for(j=0;j<8;j++){
            if((curByte&0x80000000)!=0){
                curByte <<= 1;
                curByte ^= crc32;
            }else{
                curByte <<= 1;
            }
        }
        crctable32[i] = curByte;
    }
}
int main()
{
    uint32_t i,j;
    xCrc16();
    for(i=0;i<256;i++){
        printf("%08X %08X %08X %08X %08X %08X %08X %08X\r\n",
            (crctable16[i]&crc16Mask),(crctable16[i+1]&crc16Mask),
            (crctable16[i+2]&crc16Mask),(crctable16[i+3]&crc16Mask),
            (crctable16[i+4]&crc16Mask),(crctable16[i+4]&crc16Mask),
            (crctable16[i+6]&crc16Mask),(crctable16[i+7]&crc16Mask));
        i+=7;
    }
    printf("\r\n");
    xCrc24();
    for(i=0;i<256;i++){
        printf("%08X %08X %08X %08X %08X %08X %08X %08X\r\n",
            (crctable24[i]&crc24Mask),(crctable24[i+1]&crc24Mask),
            (crctable24[i+2]&crc24Mask),(crctable24[i+3]&crc24Mask),
            (crctable24[i+4]&crc24Mask),(crctable24[i+4]&crc24Mask),
            (crctable24[i+6]&crc24Mask),(crctable24[i+7]&crc24Mask));
        i+=7;
    }
    printf("\r\n");
    xCrc32();
    for(i=0;i<256;i++){
        printf("%08X %08X %08X %08X %08X %08X %08X %08X\r\n",
            (crctable32[i]&crc32Mask),(crctable32[i+1]&crc32Mask),
            (crctable32[i+2]&crc32Mask),(crctable32[i+3]&crc32Mask),
            (crctable32[i+4]&crc32Mask),(crctable32[i+4]&crc32Mask),
            (crctable32[i+6]&crc32Mask),(crctable32[i+7]&crc32Mask));
        i+=7;
    }
    return 0;
}
