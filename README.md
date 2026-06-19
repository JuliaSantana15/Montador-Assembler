# Montador para o Processador Neander

## Descrição

Este projeto consiste na implementação de um montador (assembler) para o processador Neander, desenvolvido em linguagem C. O programa é responsável por ler um arquivo em linguagem Assembly (`.asm`), identificar as instruções pertencentes ao conjunto de instruções do Neander e gerar um arquivo de saída no formato `.mem`, contendo os respectivos códigos de operação em formato binário.

O projeto foi desenvolvido com finalidade acadêmica para auxiliar no estudo de Arquitetura de Computadores e Linguagem Assembly.

## Autores

* Júlia Santana dos Santos – SP3207439
* Nathália Oliveira dos Santos – SP3217574

## Funcionalidades

* Leitura de arquivos `.asm`;
* Reconhecimento das instruções da arquitetura Neander;
* Conversão das instruções para seus respectivos opcodes;
* Geração automática do arquivo de saída `.mem`;
* Inclusão do cabeçalho do formato de memória utilizado pelo simulador;
* Tratamento básico de erros para arquivos inexistentes e instruções inválidas.

## Conjunto de Instruções Suportado

| Instrução | Opcode |
| --------- | ------ |
| NOP       | 0x00   |
| STA       | 0x10   |
| LDA       | 0x20   |
| ADD       | 0x30   |
| OR        | 0x40   |
| AND       | 0x50   |
| NOT       | 0x60   |
| JMP       | 0x80   |
| JN        | 0x90   |
| JZ        | 0xA0   |
| HLT       | 0xF0   |

## Exemplo de Entrada

Arquivo `prog1.asm`:

```asm
LDA 80
ADD 81
STA 82
HLT
```

## Arquivo Gerado

Ao executar o programa, será criado automaticamente um arquivo chamado:

```
programa.mem
```

contendo os códigos de operação correspondentes às instruções do arquivo Assembly.

## Compilação

Utilizando GCC:

```bash
gcc montador.c -o montador
```

## Execução

```bash
./montador programa.asm
```

ou, no Windows:

```bash
montador.exe programa.asm
```

## Saída Esperada

Caso a execução seja bem-sucedida, será exibida a mensagem:

```text
Pronto, O arquivo programa.mem foi criado
```

## Tecnologias Utilizadas

* Linguagem C
* Biblioteca padrão da linguagem C (`stdio.h`, `string.h`, `stdlib.h`)

## Objetivo

O objetivo deste projeto é demonstrar o funcionamento básico de um montador para a arquitetura Neander, realizando a tradução de programas escritos em Assembly para um formato de memória executável, permitindo compreender os princípios de tradução de instruções e organização de computadores.
