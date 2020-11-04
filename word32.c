#include "word32.h"

void set_opcode(char opcode, word32 * original){
    *original = *original & 0x03FFFFFF;
    *original = *original | (opcode << 26);
}

void set_rs(char rs, word32 * original){
    *original = *original & 0xFC1FFFFF;
    *original = *original | (rs << 21);
}

void set_rt(char rt, word32 * original){
    *original = *original & 0xFFE0FFFF;
    *original = *original | (rt << 16);
}

void set_immediate(int immediate, word32 * original){
    *original = *original & 0xFFFF0000;
    *original = *original | (immediate);
}
