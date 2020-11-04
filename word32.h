/* ancienne implémentation de word32
typedef struct{
    char c1;
    char c2;
    char c3;
    char c4;
} word32;
*/

typedef unsigned int word32;

void set_opcode(char opcode, word32 * original);

void set_rs(char rs, word32 * original);

void set_rt(char rt, word32 * original);

void set_immediate(int immediate, word32 * original);
