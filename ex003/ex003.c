#include <stdio.h>

// Função para converter valores lógicos em "V" ou "F"
char converterValorLogico(int valor) {
    if (valor)
        return 'V';
    else
        return 'F';
}

// Emanuel - letra (a)

// Função que implementa a porta NAND
int portaNAND(int a, int b) {
    // Retorna o resultado da negação da operação lógica AND entre 'a' e 'b'
    return !(a && b);
}

// Antonio Pedro - letra (b)

// Função que gera a tabela verdade para a porta NAND
void tabelaNAND() {
    int a, b, resultado;

    // Imprime o cabeçalho da tabela
    printf("A  B  |  NAND\n");
    printf("--------------\n");

    // Loop para gerar todas as combinações possíveis de valores lógicos para 'a' e 'b'
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            resultado = portaNAND(a, b);
            
            // Imprime os valores de 'a', 'b' e o resultado da porta NAND e converte os valores lógicos para "V" ou "F"
            printf("%c  %c  |   %c\n", converterValorLogico(a), converterValorLogico(b), converterValorLogico(resultado));
        }
    }
}

// Erik - letra (c)

// Função que implementa a porta OR
int portaOR(int a, int b) {
    // Retorna o resultado da operação lógica OR entre 'a' e 'b'
    return a || b;
}

// Ícaro - letra (d)

// Função que gera a tabela verdade para a porta OR
void tabelaOR() {
    int a, b, resultado;

    // Imprime o cabeçalho da tabela
    printf("A  B  |   OR\n");
    printf("--------------\n");

    // Loop para gerar todas as combinações possíveis de valores lógicos para 'a' e 'b'
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            resultado = portaOR(a, b);
            
            // Imprime os valores de 'a', 'b' e o resultado da porta OR e converte os valores lógicos para "V" ou "F"
            printf("%c  %c  |   %c\n", converterValorLogico(a), converterValorLogico(b), converterValorLogico(resultado));
        }
    }
}

int main() {
    // Chamando as funções para gerar as tabelas verdade
    tabelaNAND();
    printf("\n");
    tabelaOR();

    printf("Pressione qualquer tecla para sair...");
    getchar();

    return 0;
}
