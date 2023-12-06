//
// Created by Gonçalo Cunha on 06/12/2023.
//

#include "projeto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "projeto.h"



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


// Função de teste para o requisito 1
void testRequirement1() {
    WordMatrix matrix;
    size_t rows = 2;
    size_t cols = 3;

    initializeWordMatrix(&matrix, rows, cols);

    // Adicionar palavras aos conjuntos
    addWordToMatrix(&matrix, 0, 0, "a", "");
    addWordToMatrix(&matrix, 0, 1, "b", "");
    addWordToMatrix(&matrix, 0, 2, "c", "");
    addWordToMatrix(&matrix, 1, 0, "d", "");
    addWordToMatrix(&matrix, 1, 1, "e", "");
    addWordToMatrix(&matrix, 1, 2, "f", "");


    // Imprimir a matriz
    printf("Requirement 1:\n");
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            printf("Word: %s\tUFP6 Code: %s\tBinary: %s\n",
                   matrix.entries[i][j].word,
                   matrix.entries[i][j].ufp6Code,
                   matrix.entries[i][j].binaryRepresentation);
        }
    }
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
    char *binary = (char *)malloc(7 * sizeof(char)); // 6 bits + terminador nulo
    for (int i = 5; i >= 0; --i) {
        binary[5 - i] = ((c >> i) & 1) + '0'; // Converte para '0' ou '1'
    }
    binary[6] = '\0'; // Adiciona o terminador nulo
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

typedef struct {
    char character;
    char *binary;
} BinaryMapping;

BinaryMapping mapping_num[] = {
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
};

BinaryMapping mapping_min[] ={
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
};

BinaryMapping mapping_mai[] ={
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
        {'Z', "111101"},
};

// Função para converter um caractere para sua representação binária personalizada
char* customBinaryEncoding(char c, const BinaryMapping *mapping, BinaryMapping *mapping_min, BinaryMapping *mapping_mai, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        if (mapping[i].character == c) {
            return mapping[i].binary;
        }
    }
    for (size_t i = 0; i < size; ++i) {
        if (mapping_min[i].character == c) {
            return mapping_min[i].binary;
        }
    }

    for (size_t i = 0; i < size; ++i) {
        if (mapping_mai[i].character == c) {
            return mapping_mai[i].binary;
        }
    }

    return "0000"; // Padrão para caracteres desconhecidos
}



int main_aed_lp_proj() {
    // Chamar as funções de teste
    // testRequirement1();

    //generateBinaryRepresentation();

    // Tamanho da tabela de mapeamento
    size_t mappingSize = sizeof(mapping_min) / sizeof(mapping_num[0]);


    char character = '3213';
    for (int i = 0; i < character; ++i) {
        printf("'%c' Binary: %s\n", character, customBinaryEncoding(character, mapping_num, mapping_min, mapping_mai, mappingSize));
    }


    return 0;
}