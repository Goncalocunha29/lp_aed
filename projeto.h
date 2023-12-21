//
// Created by Gonçalo Cunha on 06/12/2023.
//

#ifndef PROJETO_PROJETO_H
#define PROJETO_PROJETO_H

#include <stddef.h>

// Estrutura para armazenar palavra e seu código UFP6
typedef struct {
    char *word;
    char *ufp6Code;
    //data modificacao;
    //char *binaryRepresentation;
} WordEntry;

// Estrutura para armazenar conjunto de palavras e códigos UFP6
typedef struct {
    WordEntry **entries;
    size_t rows;
    size_t cols;
} WordMatrix;

typedef struct {
    char character;
    char *binary;
} BinaryMapping;

char* wordToBinary(const char *word);

char* charTo6BitBinary(char c);//passa o binario apenas para 6 bits

int main_aed_lp_proj();


#endif //PROJETO_PROJETO_H
