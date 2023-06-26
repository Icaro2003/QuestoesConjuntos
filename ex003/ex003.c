#include <stdio.h>

// Função que implementa a porta NAND
int portaNAND(int a, int b) {
    // Retorna o resultado da negação da operação lógica AND entre 'a' e 'b'
    return !(a && b);
}

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
            // Imprime os valores de 'a', 'b' e o resultado da porta NAND
            printf("%d  %d  |   %d\n", a, b, resultado);
        }
    }
}

// Função que implementa a porta OR
int portaOR(int a, int b) {
    // Retorna o resultado da operação lógica OR entre 'a' e 'b'
    return a || b;
}

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
            // Imprime os valores de 'a', 'b' e o resultado da porta OR
            printf("%d  %d  |   %d\n", a, b, resultado);
        }
    }
}

int main() {
    // Chamando as funções para gerar as tabelas verdade
    tabelaNAND();
    printf("\n");
    tabelaOR();

    return 0;
}
