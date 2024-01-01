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
    char *alphanumeric[100];
    char *codification[100];
    int spaceconj;
} WORDS_HOLDER;

void initializeWordMatrix(WordMatrix *matrix, size_t rows, size_t cols);
void addWordToMatrix(WordMatrix *matrix, size_t row, size_t col, char word);
char* customBinaryEncoding(char c[], const BinaryMapping *mapping, size_t size);
void testRequirement1();
int functionprint();
int functionprint2();
void saveWordSetToFile(const char *charfilename);
void saveWordSetToFile2(const char *charfilename);
int *gerwords();
void addWordRandom(char *c[]);
void randomc(char *c[]);
void removeword(char *c[], const char *palavra);
int comparec();
void searchwords(char *c[], const char *sequencesearch);
void searchwords2(const char *sequencesearch);
int comparewordsc(const void *a, const void *b);
void preencherWordsHolder(WORDS_HOLDER *holder, char *c[]);
void libertarWordsHolder(WORDS_HOLDER *holder);


int main_aed_lp_proj();


#endif //PROJETO_PROJETO_H
