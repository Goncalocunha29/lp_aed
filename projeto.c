//
// Created by Gonçalo Cunha on 06/12/2023.
//

#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// Função para inicializar a matriz de palavras e códigos UFP6
void initializeWordMatrix(WordMatrix *matrix, size_t rows, size_t cols) {
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->entries = (WordEntry **)malloc(rows * sizeof(WordEntry *));
    for (size_t i = 0; i < rows; i++) {
        matrix->entries[i] = (WordEntry *)malloc(cols * sizeof(WordEntry));
        for (size_t j = 0; j < cols; j++) {
            matrix->entries[i][j].word = NULL;
        }
    }
}

// Função para adicionar uma palavra e seu código UFP6 à matriz
void addWordToMatrix(WordMatrix *matrix, size_t row, size_t col, char word) {
    if (row < matrix->rows && col < matrix->cols) {
        free(matrix->entries[row][col].word);

        matrix->entries[row][col].word = (char *)malloc(2 * sizeof(char));
        matrix->entries[row][col].word[0] = word;
        matrix->entries[row][col].word[1] = '\0';
    } else {
        printf("Posição inválida na matriz.\n");
    }
}



BinaryMapping mapping[] = {
        {'0', "0000"},
        {'1', "1"},
        {'2', "10"},
        {'3', "11"},
        {'4', "100"},
        {'5', "101"},
        {'6', "110"},
        {'7', "111"},
        {'8', "1000"},
        {'9', "1001"},
        {'a', "1010"},
        {'b', "1011"},
        {'c', "1100"},
        {'d', "1101"},
        {'e', "1110"},
        {'f', "1111"},
        {'g', "10000"},
        {'h', "10001"},
        {'i', "10010"},
        {'j', "10011"},
        {'k', "10100"},
        {'l', "10101"},
        {'m', "10110"},
        {'n', "10111"},
        {'o', "11000"},
        {'p', "11001"},
        {'q', "11010"},
        {'r', "11011"},
        {'s', "11100"},
        {'t', "11101"},
        {'u', "11110"},
        {'v', "11111"},
        {'w', "100000"},
        {'x', "100001"},
        {'y', "100010"},
        {'z', "100011"},
        {'A', "100100"},
        {'B', "100101"},
        {'C', "100110"},
        {'D', "100111"},
        {'E', "101000"},
        {'F', "101001"},
        {'G', "101010"},
        {'H', "101011"},
        {'I', "101100"},
        {'J', "101101"},
        {'K', "101110"},
        {'L', "101111"},
        {'M', "110000"},
        {'N', "110001"},
        {'O', "110010"},
        {'P', "110011"},
        {'Q', "110100"},
        {'R', "110101"},
        {'S', "110110"},
        {'T', "110111"},
        {'U', "111000"},
        {'V', "111001"},
        {'W', "111010"},
        {'X', "111011"},
        {'Y', "111100"},
        {'Z', "111101"}
};



// Função para converter um caractere para sua representação binária personalizada
char* customBinaryEncoding(char c[], const BinaryMapping *mapping, size_t size) {
    char *str1 = malloc(100);
    str1[0] = '\0';

        for(int j = 0; c[j] != '\0'; j++){
            for (size_t i = 0; i < size; ++i) {
            //printf("%c\n", c[i]);
                if (mapping[i].character == c[j]) {
                    strcat(str1, mapping[i].binary);
                }
            }
        }

    return str1; // Padrão para caracteres desconhecidos
}

int functionprint(){
    // Tamanho da tabela
    size_t mappingSize = sizeof(mapping) / sizeof(mapping[0]);

    char *c1[100]= {"o", //11000
                   "Ola", //110010101011010
                   "Xpto",
                   "LP",
                   "1",
                   "aba"}; //1010 1011 1010

    printf("Conjunto 1: \n");

    for (int i = 0; i < strlen(c1) ; ++i) {
        char *teste;
        teste = customBinaryEncoding(c1[i], mapping,mappingSize);
        printf("%s\n", teste);

    }

}

int functionprint2(){
    size_t mappingSize = sizeof(mapping) / sizeof(mapping[0]);

    char* c2[100]= {"b",
                   "Mundo",
                   "PL",
                   "11"
                   };

    printf("\nConjunto 2: \n");

    for (int i = 0; i < strlen(c2); ++i) {
        char *teste;
        teste = customBinaryEncoding(c2[i], mapping, mappingSize);
        printf("%s\n", teste);

    }

}



//adicionar uma ou mais palavras ... mais tarde uso de files para ler as palavras

int insertword(){
    size_t mappingSize = sizeof(mapping) / sizeof(mapping[0]);
    WordMatrix matrix;
    size_t rows = 10;
    size_t cols = 7;

    char *c1[100]={"a", "b", "c", "1", "o"};

    for (int i = 0; i < strlen(c1); ++i) {
        char* randomWord;
        randomWord = customBinaryEncoding(c1[i], mapping, mappingSize);
        printf("%s\n", randomWord);
    }
    /*
    for (size_t i = 0; i < rows; ++i) {
        char palavra[11];


        if (fgets(palavra, sizeof(palavra), stdin) != NULL) {
            size_t length = strcspn(palavra, "\n");
            if (palavra[length] == '\n') {
                palavra[length] = '\0';
            }
            for (size_t j = 0; palavra[j] != '\0'; j++) {
                addWordToMatrix(&matrix, i, j, palavra[j]);
            }
        } else {
            printf("Erro ao ler a entrada.\n");
        }
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            //printf("Word: %s\tUFP6 Code: %s\tBinary: %s\n",
                   //matrix.entries[i][j].word,
                   //matrix.entries[i][j].ufp6Code,
                   //matrix.entries[i][j].binaryRepresentation);
            if(matrix.entries[i][j].word){
                printf("[%s]",matrix.entries[i][j].word);
            }else{
                printf("[ ]");
            }
        }
        printf("\n");
    }
    */
}

//remover uma ou mais palavras

int removeword(){


}

//compara as palavras dos conjuntos

int comparewords(){

    if(functionprint() == functionprint2()){
        printf("\n1");
    }else{
        printf("0\n");
    }
    return 0;
}

//pesquisa palavras nos conjuntos e pretende-se encontrar todas as palavras
//que contêm essa sequência de pesquisa. Deverá ainda ser possível obter os
//códigos binários das palavras encontrados na pesquisa

int searchwords(){

}

//Implementar funções para ordenar os conjuntos de palavras e respectivos códigos
//UFP6, por ordem alfabética (crescente ou decrescente) ou por ordem de tamanho
//das palavras (também crescente ou decrescente)

int ordinaryfunction(){

}


void testRequirement1() {

    WordMatrix matrix;
    size_t rows = 10;
    size_t cols = 7;

    initializeWordMatrix(&matrix, rows, cols);

    for (size_t i = 0; i < rows; ++i) {
        char palavra[11];
        printf("Digite uma palavra %d (max. 7 caracteres):", i+1);

        if (fgets(palavra, sizeof(palavra), stdin) != NULL) {
            size_t length = strcspn(palavra, "\n");
            if (palavra[length] == '\n') {
                palavra[length] = '\0';
            }
            for (size_t j = 0; palavra[j] != '\0'; j++) {
                addWordToMatrix(&matrix, i, j, palavra[j]);
            }
        } else {
            printf("Erro ao ler a entrada.\n");
        }
    }

    // Imprimir a matriz
    printf("Requirement 1:\n");
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            /*printf("Word: %s\tUFP6 Code: %s\tBinary: %s\n",
                   matrix.entries[i][j].word,
                   matrix.entries[i][j].ufp6Code,
                   matrix.entries[i][j].binaryRepresentation);*/
            if(matrix.entries[i][j].word){
                printf("[%s]",matrix.entries[i][j].word);
            }else{
                printf("[ ]");
            }
        }
        printf("\n");
    }
    size_t mappingSize = sizeof(mapping) / sizeof(mapping[0]);
    printf("Conversion 1:\n");
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            /*printf("Word: %s\tUFP6 Code: %s\tBinary: %s\n",
                   matrix.entries[i][j].word,
                   matrix.entries[i][j].ufp6Code,
                   matrix.entries[i][j].binaryRepresentation);*/
            if(matrix.entries[i][j].word){
                printf("%s |",customBinaryEncoding(matrix.entries[i][j].word, mapping,mappingSize));

            }else{
                printf(" | ");
            }
        }
        printf("\n");
    }
}

int main_aed_lp_proj() {
    // Chamar as funções de teste
    //testRequirement1();

    //generateBinaryRepresentation();
    //functionprint();
    //functionprint2();


    //comparewords();


    insertword();

    return 0;
}