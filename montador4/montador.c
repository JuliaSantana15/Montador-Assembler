#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Instrucao {
    char nome[4]; // o nome da instrucao
    unsigned char opcode;
    int precisa_valor;
};

// linguagem do neander
struct Instrucao instrucoes[] = {
    {"NOP", 0x00, 0},
    {"STA", 0x10, 1},
    {"LDA", 0x20, 1},
    {"ADD", 0x30, 1},
    {"OR",  0x40, 1},
    {"AND", 0x50, 1},
    {"NOT", 0x60, 0},
    {"JMP", 0x80, 1},
    {"JN",  0x90, 1},
    {"JZ",  0xA0, 1},
    {"HLT", 0xF0, 0}
};

int main(int qtd, char *arg[]) {
    if (qtd < 2) {
        printf("Coloque o nome do arquivo .asm pra funcionar, tipo: %s programa.asm\n", arg[0]); // nome do programa
        return 1;
    }

    FILE *arqasm = fopen(arg[1], "r"); // abrir .asm modo leitura
    if (arqasm == NULL) {
        printf("Não foi possível abrir o arquivo: %s\n", arg[1]); // nome do arquivo
        return 1;
    }

    char nomef[100]; // copiar nome do arquivo
    strcpy(nomef, arg[1]);

    char *p = strchr(nomef, '.'); // trocar a extensão
    if (p != NULL) {
        strcpy(p, ".mem");
    } else {
        strcat(nomef, ".mem");
    }

    FILE *arqmem = fopen(nomef, "wb"); // cria o arquivo .mem
    if (arqmem == NULL) {
        printf("Deu erro criando o arquivo de saída\n");
        fclose(arqasm);
        return 1;
    }

    // cabecalho do .mem 
    unsigned char cabecalho[4] = {0x03, 0x4E, 0x44, 0x52};
    fwrite(cabecalho, 1, 4, arqmem);

    char linha[100];
    while (fgets(linha, 100, arqasm)) {
        char comando[10];
        int valor = 0;

        int partes = sscanf(linha, "%s %d", comando, &valor); // qtd coisas lidas

        int achei = 0; // procura instrucao no vetor
        for (int i = 0; i < 11; i++) {
            if (strcmp(comando, instrucoes[i].nome) == 0) {
                fputc(instrucoes[i].opcode, arqmem);
                fputc(0x00, arqmem); 

                if (instrucoes[i].precisa_valor && partes == 2) {
                    fputc((unsigned char)valor, arqmem);
                    fputc(0x00, arqmem);
                }

                achei = 1;
                break;
            }
        }

        if (!achei) {
            printf("Não foi reconhecida a instrução: %s\n", comando);
        }
    }

    fclose(arqasm);
    fclose(arqmem);

    printf("Pronto, O arquivo %s foi criado\n", nomef);

    return 0;
}
