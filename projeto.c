//
// Created by Gonçalo Cunha on 06/12/2023.
//

#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




// Função para inicializar a matriz de palavras e códigos UFP6
void initializeWordMatrix(WordMatrix *matrix, size_t rows, size_t cols) {
    matrix->entries = (WordEntry **)malloc(rows * sizeof(WordEntry *));
    for (size_t i = 0; i < rows; ++i) {
        matrix->entries[i] = (WordEntry *)malloc(cols * sizeof(WordEntry));
    }
    matrix->rows = rows;
    matrix->cols = cols;
}

// Função para adicionar uma palavra e seu código UFP6 à matriz
void addWordToMatrix(WordMatrix *matrix, size_t row, size_t col, const char *word, const char *ufp6Code) {
    matrix->entries[row][col].word = strdup(word);
    matrix->entries[row][col].ufp6Code = strdup(ufp6Code);
    matrix->entries[row][col].binaryRepresentation = wordToBinary(word);
}



// Função para converter uma palavra para binário
char* wordToBinary(const char *word) {
    size_t len = strlen(word);
    char *binary = (char *)malloc((8 * len + 1) * sizeof(char)); // Cada caractere requer 6 bits

    for (size_t i = 0; i < len; ++i) {
        char currentChar = word[i];
        for (int j = 7; j >= 0; --j) {
            binary[8 * i + (7 - j)] = ((currentChar >> j) & 1) + '0'; // Converte para '0' ou '1'
        }
    }
    binary[8* len] = '\0'; // Adiciona o caractere nulo no final


    return binary;
}

char* charTo6BitBinary(char c) {
    char *binary = (char *)malloc(7 * sizeof(char)); // 6 bits + nulo
    for (int i = 5; i >= 0; --i) {
        binary[5 - i] = ((c >> i) & 1) + '0'; // Converte para '0' ou '1'
    }
    binary[6] = '\0'; // Adiciona o nulo
    return binary;
}

// Função para gerar a representação binária para letras de 'a' a 'z' e números de 0 a 9
void generateBinaryRepresentation() {
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        printf("'%c' Binary: %s\n", ch, charTo6BitBinary(ch));
    }

    for (char digit = '0'; digit <= '9'; ++digit) {
        printf("'%c' Binary: %s\n", digit, charTo6BitBinary(digit));
    }
}


BinaryMapping mapping[] = {
        {'0', "0000"},
        {'1', "0001"},
        {'2', "0010"},
        {'3', "0011"},
        {'4', "0100"},
        {'5', "0101"},
        {'6', "0110"},
        {'7', "0111"},
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
char* customBinaryEncoding(char c, const BinaryMapping *mapping, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (mapping[i].character == c) {
            return mapping[i].binary;
        }
    }

    return "0000"; // Padrão para caracteres desconhecidos
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

    char *p;
    char c2[100]= {"b"
                   "Mundo"
                   "PL"
                   "11"
                   };
    int size;
    size = 9;
    p = (char*) malloc(sizeof (char)*10);
    printf("\nConjunto 2: \n");
    for (int i = 0; i < size; ++i) {
        //p[i] = c2[i];
        //printf("%p = %c\n", &p[i], p[i]);
    }

    //teste
    //for (int i = 0; i < 9; ++i) {
      //printf("'%c' -> %s\n", p[i], customBinaryEncoding(p[i], mapping,mappingSize));
    //}

    //print a 1 palavra
    /*for (int i = 0; i < 1 ; ++i) {
        printf("%s", customBinaryEncoding(p[i], mapping,mappingSize));
    }
    printf("\n");
    //print a 2 palavra
    for (int i = 1; i < 6 ; ++i) {
        printf("%s", customBinaryEncoding(p[i], mapping,mappingSize));
    }
    printf("\n");
    //print a 3 palavra
    for (int i = 6; i < 8 ; ++i) {
        printf("%s", customBinaryEncoding(p[i], mapping,mappingSize));
    }
    printf("\n");
    //print a 4 palavra
    for (int i = 8; i < 10 ; ++i) {
        printf("%s", customBinaryEncoding(p[i], mapping,mappingSize));
    }*/

}



//adicionar uma ou mais palavras ... mais tarde uso de files para ler as palavras

int insertword(){


}

//remover uma ou mais palavras

int removeword(){


}

//compara as palavras dos conjuntos

int comparewords(){

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



int main_aed_lp_proj() {
    // Chamar as funções de teste
    testRequirement1();

    //generateBinaryRepresentation();
    //functionprint();
    //functionprint2();


    return 0;
}