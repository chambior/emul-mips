#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "word32.h"

int main(void){
    char * line = malloc(sizeof(char)*64);
    char * arg1 = malloc(sizeof(char)*16);
    char * arg2 = malloc(sizeof(char)*16);
    char * arg3 = malloc(sizeof(char)*16);
    word32 instruction = 0x00000000;
    char instruction_type;

    FILE * fic = fopen("mips-examples/ex1.s", "r");
    if(fic==NULL){
        perror("[ERR] Problème d'ouverture du fichier");
        exit(1);
    }

    while(!feof(fic)){
        fscanf(fic, "%s", line);

        instruction_type = get_instruction_type(line);

        if(instruction_type == 'I'){
            if(string_equal(line, "ADDI")){
                set_opcode(0x08, &instruction);
            }


            
            fscanf(fic, "%s", arg1);
            fscanf(fic, "%s", arg2);
            fscanf(fic, "%s", arg3);

            remove_period(arg1);
            remove_period(arg2);

            set_rs(get_reg(arg1), &instruction);
            set_rt(get_reg(arg2), &instruction);
            set_immediate(get_immediate(arg3), &instruction);

            printf("0x%08x\n", instruction);
        }


        fscanf(fic,"\n");
    }

    return 0;
}
