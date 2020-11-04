#include "string.h"
#include <stdio.h>


short string_equal(string a, string b){
    short res = 0;
    short egal = 1;
    short i = 0;

    while((a[i] != 0) && (b[i] != 0) && egal){
        res = b[i] - a[i];
        if(res != 0) egal = 0;
        i++;
    }

    return egal;
}


void remove_period(string s){
    int i = 0;
    while((s[i]) != ',' && s[i] != 0) i++;
    s[i] = 0;
}


char get_reg(string s){
    char res = 0;
    if(s[0] == '$'){
        if(s[1] >= 48 && s[1] <= 57){ /*Cas d'un nombre*/
            if(s[2] == 0) res = s[1] - 48;
            else res = 10 * (s[1] - 48) + (s[2]-48);
        }
        else{ /*Cas d'une lettre*/
            res=0; /*WIP*/
        }
    }
    else res = 0;
    return res;
}


int get_immediate(string s){
    int res = 0;
    int i = 0;
    short signe = 1;
    if(s[i] == '-'){
        signe = -1;
        i++;
    }
    while (s[i] != 0) {
        res = 10*res + (s[i] - 48);
        i++;
    }
    if((res > 32767) | (res < -32768)) perror(
        "[ERR] Les valeurs immédiates doivent être comprises entre -32768 et 32767");
    res = signe * res;
    if(res<0){
        res = res & 0x7FFF;
        res = res | 0x8000;
    }

    return res;
}




char get_instruction_type(string s){
    char res = 0;
    if(string_equal(s, "ADDI")) res = 'I';
    return res;
}
