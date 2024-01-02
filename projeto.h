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


typedef struct {
    WORDS_HOLDER *wordsHolder;
    char latsupdate[20];
}VAL_AD_WORDS_HOLDER;

typedef struct {
    size_t size; //tamanho do array
    size_t ocup; // Numero de elementos ou ocupados ou inseridos
    VAL_AD_WORDS_HOLDER *array;
}AD_WORDS_HOLDER;

void initializeWordMatrix(WordMatrix *matrix, size_t rows, size_t cols);
void addWordToMatrix(WordMatrix *matrix, size_t row, size_t col, char word);
char* customBinaryEncoding(char c[], const BinaryMapping *mapping, size_t size);
void testRequirement1();
int functionprint(char *c[]);
void saveWordSetToFile(const char *charfilename);
int *gerwords();
void addWordRandom(char *c[]);
void randomc(char *c[]);
void removeword(char *c[], const char *palavra);
int comparec(char *c[], char *conj[]);
void searchwords(char *c[], const char *sequencesearch);
int comparewordsc(const void *a, const void *b);
void preencherWordsHolder(WORDS_HOLDER *holder, char *c[], char *conj[]);
void libertarWordsHolder(WORDS_HOLDER *holder);


int main_aed_lp_proj();


#endif //PROJETO_PROJETO_H
