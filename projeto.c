//
// Created by Gonçalo Cunha on 06/12/2023.
//

#include "projeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>




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
        {'0', "0"},
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


size_t mappingSize = sizeof(mapping) / sizeof(mapping[0]);

char* c1[100]= {"o", //11000
                "Ola", //110010101011010
                "Xpto",
                "LP",
                "9",
                "1",
                "Zebra",
                "aba",//101010111010
                "p"

};

char* c2[100]= {"b", //1011
                "Mundo",
                "Canguru",
                "PL",
                "11",//11
                "Xpto",
                "Ola",
                "p",
                "q"

};

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
            if(matrix.entries[i][j].word){
                printf("[%s]",matrix.entries[i][j].word);
            }else{
                printf("[ ]");
            }
        }
        printf("\n");
    }

    printf("Conversion 1:\n");
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if(matrix.entries[i][j].word){
                printf("%s\t|\t",customBinaryEncoding(matrix.entries[i][j].word, mapping,mappingSize));

            }else{
                printf("\t|\t");
            }
        }
        printf("\n");
    }
}


// Função para converter um caracter para sua representação binária personalizada
char *customBinaryEncoding(char c[], const BinaryMapping *mapping, size_t size) {
    char *str1 = malloc(10000);
    str1[0] = '\0';

        for(int j = 0; c[j] != '\0'; j++){
            for (size_t i = 0; i < size; ++i) {
                if (mapping[i].character == c[j]) {
                    strcat(str1, mapping[i].binary);
                }
            }
        }

    return str1; // Padrão para caracteres desconhecidos
}


int functionprint(char *c[]){

    if(c == c1){
        printf("Conjunto 1: \n");
    }else{
        printf("Conjunto 2: \n");
    }
    char *teste;
    for (int i = 0; i < 100 && c[i]!=NULL ; ++i) {
        teste = customBinaryEncoding(c[i], mapping,mappingSize);
        printf("%s\n", teste);

    }

    free(teste);
}


// passar os conjuntos para file

void saveWordSetToFile(const char *charfilename) {
    FILE *file = fopen(charfilename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char *teste;
    fprintf(file, "Conjunto 1:\n");
    for (int i = 0; i < 100 && c1[i] != NULL; ++i) {
        teste = customBinaryEncoding(c1[i], mapping, mappingSize);
        fprintf(file, "%s\t%s\n", c1[i], teste);
    }
    fprintf(file, "\nConjunto2:\n");
    for (int i = 0; i < 100 && c2[i] != NULL; ++i) {
        char *teste3 = customBinaryEncoding(c2[i], mapping, mappingSize);
        fprintf(file, "%s\t%s\n", c2[i], teste3);
    }


    free(teste);
    fclose(file);

}


//adicionar uma ou mais palavras ... mais tarde uso de files para ler as palavras

int *gerwords() {

    int tamanho = rand() % 7 + 1; // tamanho maximo da palavra
    char *palavra = (char *)malloc((tamanho + 1) * sizeof(char));

    for (int i = 0; i < tamanho; ++i) {
        palavra[i] = 'a' + rand() % 26; // Caracteres aleatórios de 'a' a 'z'

    }

    palavra[tamanho] = '\0';
    return palavra;
}

void addWordRandom(char *c[]){
    for (int i = 0; i < 100; ++i) {
        if (c[i] == NULL) {
            c[i] = gerwords();
            break;
        }
    }
}

void randomc(char *c[]){
    srand((unsigned int)time(NULL));
    char *teste;
    for (int i = 0; i < 5; ++i) {
        addWordRandom(c);
    }
    if(c == c1){
        printf("Novo Conjunto 1:\n");
    }else{
        printf("Novo Conjunto 2:\n");
    }

    for (int i = 0; i < 100 && c[i] != NULL; ++i) {
        printf("|%s|\t", c[i]);
    }
    printf("\n");
    for (int i = 0; i < 100 && c[i] != NULL; ++i) {
        printf("%s\t ", c[i]);

        teste = customBinaryEncoding(c[i], mapping, mappingSize);
        printf("%s\n", teste);
    }
    for (int i = 0; i < 100 && c[i] != NULL; ++i) {
        free(c[i]);
    }
    free(teste);
}

//remover uma ou mais palavras

void removeword(char *c[], const char *palavra) {
    int found = 0;
    for (int i = 0; i < 100 && c[i] != NULL; ++i) {
        if (strcmp(c[i], palavra) == 0) {
            found = 1;
            // Desloca as palavras restantes
            for (int j = i; c[j] != NULL; ++j) {
                c[j] = c[j + 1];
            }

        }
    }
    if(found){
        char *teste;
        printf("\nConjunto apos remover '%s':\n", palavra);
        for (int i = 0; i < 100 && c[i] != NULL; ++i) {

            teste = customBinaryEncoding(c[i], mapping, mappingSize);
            printf("%s\t%s\n", c[i], teste);
        }
        free(teste);
    }else{
        printf("\n'%s' nao foi encontrada no conjunto\n", palavra);
    }
    // Libera a memória alocada para as palavras geradas e seus binários
    for (int i = 0; i < 100 && c[i] != NULL; ++i) {
        free(c[i]);
    }


}



//compara as palavras dos conjuntos

int comparec(char *c[], char *conj[]) {
    int found = 0;

    for (int i = 0; i < 100 && c[i] != NULL; ++i) {
        for (int j = 0; j < 100 && conj[j] != NULL; ++j) {
            // Verifica se as combinações são iguais
            if (strcmp(c[i], conj[j]) == 0) {
                found = 1;
                char *tent = customBinaryEncoding(c[i], mapping, mappingSize);
                char *te = customBinaryEncoding(conj[j], mapping, mappingSize);

                printf("Combinacao encontrada:\n");
                printf("Conjunto 1: %s\t Binario: %s\n", c[i], tent);
                printf("Conjunto 2: %s\t Binario: %s\n", conj[j], te);
            }

        }
    }
    if(!found){
        printf("Nao foi encontrada nenhuma combinacao\n");
    }
    for (int i = 0; i < 100 && c[i] != NULL; ++i) {
        free(c[i]);
    }
    for (int i = 0; i < 100 && conj[i] != NULL; ++i) {
        free(conj[i]);
    }
}



//pesquisa palavras nos conjuntos e pretende-se encontrar todas as palavras
//que contêm essa sequência de pesquisa. Deverá ainda ser possível obter os
//códigos binários das palavras encontrados na pesquisa

void searchwords(char *c[], const char *sequencesearch){
    printf("Palavras encontradas na pesquisa '%s':\n", sequencesearch);
    char *test;
    int found = 0;
    for (int i = 0; i < 100 && c[i] != NULL; ++i) {
        if (strstr(c[i], sequencesearch) != NULL) {
            found = 1;
            test = customBinaryEncoding(c[i], mapping, mappingSize);
            printf("Palavra: %s\tCodigo Binario: %s\n", c[i], test);
        }
    }
    if(!found){
        printf("Nao foram encontradas palavras com '%s'", sequencesearch);
    }

    printf("\n");
    for (int i = 0; i < 100 && c1[i] != NULL; ++i) {
        free(c1[i]);
    }
    for (int i = 0; i < 100 && c2[i] != NULL; ++i) {
        free(c2[i]);
    }

    free(test);


}


//Implementar funções para ordenar os conjuntos de palavras e respectivos códigos
//UFP6, por ordem alfabética (crescente ou decrescente) ou por ordem de tamanho
//das palavras (também crescente ou decrescente)

int comparewordsc(const void *a, const void *b) {
    const WordEntry *palavraA = (const WordEntry *)a;
    const WordEntry *palavraB = (const WordEntry *)b;
    return strcmp(palavraA->word, palavraB->word);
}

int ordinaryFunctionAlpha(char *c[], int tamanho){
    // Criar um array de estruturas WordEntry para armazenar palavras e códigos
    WordEntry *entradas = malloc(tamanho * sizeof(WordEntry));

    // Preencher o array WordEntry
    for (int i = 0; i < tamanho; ++i) {
        //char *teste;
        //teste = customBinaryEncoding(c[i], mapping, mappingSize);
        entradas[i].word = c[i];
        entradas[i].ufp6Code = customBinaryEncoding(c[i], mapping, mappingSize);
        //free(teste);
    }

    // Ordenar o array WordEntry usando qsort
    qsort(entradas, tamanho, sizeof(WordEntry), comparewordsc);

    // Atualizar os conjuntos com as palavras e códigos ordenados
    for (int i = 0; i < tamanho; ++i) {
        char *teste;
        teste = customBinaryEncoding(entradas[i].word, mapping, mappingSize);
        c[i] = strdup(entradas[i].word);
        teste[i] = *entradas[i].ufp6Code;
        free(teste);
    }

    // Libertar a memória alocada
    free(entradas);

    return 1;
}


// Topico 7:

void preencherWordsHolder(WORDS_HOLDER *holder, char *c[], char *conj[]){
    //Copia palavras alfanuméricas para o WORDS_HOLDER

    for (int i = 0; c[i] != NULL && i < 100; ++i) {
        holder->alphanumeric[i] = strdup(c[i]);
        char *codification = customBinaryEncoding(c[i], mapping, mappingSize);
        holder->codification[i] = strdup(codification);
        free(codification);
    }

    for (int i = 0; conj[i] != NULL && i < 100; ++i) {
        holder->alphanumeric[i + strlen(c)] = strdup(conj[i]);  // Inicia a partir do momento em que o c1 acaba
        char *codification = customBinaryEncoding(conj[i], mapping, mappingSize);
        holder->codification[i + strlen(c)] = strdup(codification);  // Inicia a partir do momento em que o c1 acaba
        free(codification);
    }


}

void inicializeWordsHolder(WORDS_HOLDER *holder) {
    holder->spaceconj = 0;
    for (int i = 0; i < 100; ++i) {
        holder->alphanumeric[i] = NULL;
        holder->codification[i] = NULL;
    }
}

void WordsHolder(WORDS_HOLDER *holder) {
    printf("\nPalavras na estrutura:\n");
    for (int i = 0; i < holder->alphanumeric[i]; ++i) {
        printf("%s\t%s\n", holder->alphanumeric[i], holder->codification[i]);
    }

}


void libertarWordsHolder(WORDS_HOLDER *holder){
    for (int i = 0; i < holder->spaceconj; ++i) {
        free(holder->alphanumeric[i]);
        free(holder->codification[i]);
    }
    holder->spaceconj = 0;
}

// Topico 8:

AD_WORDS_HOLDER ADWords(size_t sizein){
    AD_WORDS_HOLDER holder;
    holder.size = sizein;
    holder.ocup = 0;
    holder.array = (VAL_AD_WORDS_HOLDER*) malloc(sizein* sizeof (VAL_AD_WORDS_HOLDER));

    if(holder.array == NULL){
        perror("Erro!\n");
        exit(EXIT_FAILURE);
    }

    return holder;
}

// redimensionar o AD_WORDS_HOLDER
void redADWords(AD_WORDS_HOLDER *holder, size_t nsize){
    holder->array = (VAL_AD_WORDS_HOLDER *)realloc(holder->array, nsize * sizeof(VAL_AD_WORDS_HOLDER));

    if(holder->array == NULL){
        perror("Erro!\n");
        exit(EXIT_FAILURE);
    }

    holder->size = nsize;
}


void addADWords(AD_WORDS_HOLDER *holder, const VAL_AD_WORDS_HOLDER *val) {
    if (holder->ocup == holder->size) {
        //redimensionar o array
        redADWords(holder, holder->size * 2);
    }

    holder->array[holder->ocup] = *val;
    holder->ocup++;
}

//libera memoria alocada em AD_WORDS_HOLDER
void freeADWordsHolder(AD_WORDS_HOLDER *holder) {
    for (size_t i = 0; i < holder->ocup; ++i) {
        // Libera a memória alocada para as palavras geradas e seus binários
        for (size_t j = 0; j < holder->array[i].wordsHolder->spaceconj; ++j) {
            free(holder->array[i].wordsHolder->alphanumeric[j]);
            free(holder->array[i].wordsHolder->codification[j]);
        }
    }
    free(holder->array);
    holder->array = NULL;
    holder->size = 0;
    holder->ocup = 0;
}

// Função para inicializar uma WORDS_HOLDER
void initializeWordsHolder(WORDS_HOLDER *holder) {
    holder->spaceconj = 0;


    if (holder->alphanumeric == NULL || holder->codification == NULL) {
        perror("Erro ao alocar memória para WORDS_HOLDER");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 100; ++i) {
        holder->alphanumeric[i] = NULL;
        holder->codification[i] = NULL;
    }
}

// Função para adicionar uma palavra à WORDS_HOLDER
void addWordToWordsHolder(WORDS_HOLDER *holder, const char *word, const char *codification) {
    if (holder->spaceconj < 100) {
        holder->alphanumeric[holder->spaceconj] = strdup(word);
        holder->codification[holder->spaceconj] = strdup(codification);
        holder->spaceconj++;
    } else {
        printf("A WORDS_HOLDER está cheia!\n");
    }
}

// Função para imprimir o conteúdo de uma WORDS_HOLDER
void printWordsHolder(const WORDS_HOLDER *holder) {
    printf("Palavras na estrutura:\n");
    for (int i = 0; i < holder->spaceconj; ++i) {
        printf("%s\t%s\n", holder->alphanumeric[i], holder->codification[i]);
    }
}


int main_aed_lp_proj() {
    // Chamar as funções de teste
    //testRequirement1();

    //functionprint(c1);
    //functionprint(c2);

    //randomc(c1);
    //randomc(c2);

    //saveWordSetToFile("palavras.txt");


    //remover palavras dos conjuntos
    //removeword(c1, "Ola");
    //removeword(c2, "11");


    //comparec(c1, c2);

    //searchwords(c1, "o");
    //searchwords(c2, "X");

    /* ainda nao esta finializado*/
    ordinaryFunctionAlpha(c1, strlen(c1));
    printf("Conjunto 1 ordenado:\n");
    for (int i = 0; i < 100 && c1[i] != NULL; ++i) {
        char *teste;
        teste = customBinaryEncoding(c1[i], mapping, mappingSize);
        printf("%s\t%s\n", c1[i], teste);
    }

    ordinaryFunctionAlpha(c2, strlen(c2));
    printf("\nConjunto 2 ordenado:\n");
    for (int i = 0; i < 100 && c2[i] != NULL; ++i) {
        char *teste2;
        teste2 = customBinaryEncoding(c2[i], mapping, mappingSize);
        printf("%s\t%s\n", c2[i], teste2);
    }




    //------------------------TOPICO 7-----------------------------

    /*
    WORDS_HOLDER holder;


    inicializeWordsHolder(&holder);
    preencherWordsHolder(&holder, c1, c2);
    // Exibição das palavras alfanuméricas
    printf("Palavras Alfanumericas:\n");
    for (int i = 0; holder.alphanumeric[i] != NULL; ++i) {
        printf("[%s]    ", holder.alphanumeric[i]);
    }

    // Exibição das palavras codificadas
    printf("\n\nPalavras Codificadas:\n");
    for (int i = 0; holder.codification[i] != NULL; ++i) {
        printf("[%s]\n", holder.codification[i]);
    }
    WordsHolder(&holder);
    libertarWordsHolder(&holder);
    */
    //------------------------TOPICO 8-----------------------------
    //nao esta finalizado
    /*
    AD_WORDS_HOLDER adHolder = ADWords(10);
    VAL_AD_WORDS_HOLDER val;
    initializeWordsHolder(&val.wordsHolder);
    addWordToWordsHolder(&val.wordsHolder, "palavra1", "codificacao1");
    addWordToWordsHolder(&val.wordsHolder, "palavra2", "codificacao2");

    addADWords(&adHolder, &val);
    freeADWordsHolder(&adHolder);
    */



    return 0;
}
