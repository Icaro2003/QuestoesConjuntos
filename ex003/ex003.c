#include <stdio.h>

// Fun��o para converter valores l�gicos em "V" ou "F"
char converterValorLogico(int valor) {
    if (valor)
        return 'V';
    else
        return 'F';
}

// Emanuel - letra (a)

// Fun��o que implementa a porta NAND
int portaNAND(int a, int b) {
    // Retorna o resultado da nega��o da opera��o l�gica AND entre 'a' e 'b'
    return !(a && b);
}

// Antonio Pedro - letra (b)

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
            
            // Imprime os valores de 'a', 'b' e o resultado da porta NAND e converte os valores l�gicos para "V" ou "F"
            printf("%c  %c  |   %c\n", converterValorLogico(a), converterValorLogico(b), converterValorLogico(resultado));
        }
    }
}

// Erik - letra (c)

// Fun��o que implementa a porta OR
int portaOR(int a, int b) {
    // Retorna o resultado da opera��o l�gica OR entre 'a' e 'b'
    return a || b;
}

// �caro - letra (d)

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
            
            // Imprime os valores de 'a', 'b' e o resultado da porta OR e converte os valores l�gicos para "V" ou "F"
            printf("%c  %c  |   %c\n", converterValorLogico(a), converterValorLogico(b), converterValorLogico(resultado));
        }
    }
}

int main() {
    // Chamando as fun��es para gerar as tabelas verdade
    tabelaNAND();
    printf("\n");
    tabelaOR();

    printf("Pressione qualquer tecla para sair...");
    getchar();

    return 0;
}
