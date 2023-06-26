#include <stdio.h>

// Fun��o que implementa a porta NAND
int portaNAND(int a, int b) {
    // Retorna o resultado da nega��o da opera��o l�gica AND entre 'a' e 'b'
    return !(a && b);
}

// Fun��o que gera a tabela verdade para a porta NAND
void tabelaNAND() {
    int a, b, resultado;

    // Imprime o cabe�alho da tabela
    printf("A  B  |  NAND\n");
    printf("--------------\n");

    // Loop para gerar todas as combina��es poss�veis de valores l�gicos para 'a' e 'b'
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            resultado = portaNAND(a, b);
            // Imprime os valores de 'a', 'b' e o resultado da porta NAND
            printf("%d  %d  |   %d\n", a, b, resultado);
        }
    }
}

// Fun��o que implementa a porta OR
int portaOR(int a, int b) {
    // Retorna o resultado da opera��o l�gica OR entre 'a' e 'b'
    return a || b;
}

// Fun��o que gera a tabela verdade para a porta OR
void tabelaOR() {
    int a, b, resultado;

    // Imprime o cabe�alho da tabela
    printf("A  B  |   OR\n");
    printf("--------------\n");

    // Loop para gerar todas as combina��es poss�veis de valores l�gicos para 'a' e 'b'
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            resultado = portaOR(a, b);
            // Imprime os valores de 'a', 'b' e o resultado da porta OR
            printf("%d  %d  |   %d\n", a, b, resultado);
        }
    }
}

int main() {
    // Chamando as fun��es para gerar as tabelas verdade
    tabelaNAND();
    printf("\n");
    tabelaOR();

    return 0;
}
