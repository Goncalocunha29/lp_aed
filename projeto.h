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


typedef struct {
    char *alphanumeric[10000];
    char *codification[10000];
} WORDS_HOLDER;

char* wordToBinary(const char *word);

char* charTo6BitBinary(char c);//passa o binario apenas para 6 bits


void addRandomWord(WordMatrix set);

int main_aed_lp_proj();


#endif //PROJETO_PROJETO_H
