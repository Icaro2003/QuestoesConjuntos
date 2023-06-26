#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct {
    int elementos[10];
    int tamanho;
} Conjunto;

void inicializarConjunto(Conjunto* conjunto) {
    conjunto->tamanho = 0;
}

void adicionarElemento(Conjunto* conjunto, int elemento) {
    if (conjunto->tamanho < 10) {
        conjunto->elementos[conjunto->tamanho++] = elemento;
    }
}

void imprimirConjunto(Conjunto conjunto) {
    printf("{ ");
    for (int i = 0; i < conjunto.tamanho; i++) {
        printf("%d ", conjunto.elementos[i]);
    }
    printf("}\n");
}

void complementoUniversal(Conjunto conjunto) {
    Conjunto complemento;
    inicializarConjunto(&complemento);

    int universo[] = {3, 4, 5, 6, 7, 8, 9, 10, 11};
    int tamanhoUniverso = sizeof(universo) / sizeof(universo[0]);

    for (int i = 0; i < tamanhoUniverso; i++) {
        int encontrado = 0;
        for (int j = 0; j < conjunto.tamanho; j++) {
            if (conjunto.elementos[j] == universo[i]) {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            adicionarElemento(&complemento, universo[i]);
        }
    }

    printf("Complemento Universal: ");
    imprimirConjunto(complemento);
}

void diferencaSimetrica(Conjunto conjuntoA, Conjunto conjuntoB) {
    Conjunto diferenca;
    inicializarConjunto(&diferenca);

    for (int i = 0; i < conjuntoA.tamanho; i++) {
        int encontrado = 0;
        for (int j = 0; j < conjuntoB.tamanho; j++) {
            if (conjuntoA.elementos[i] == conjuntoB.elementos[j]) {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            adicionarElemento(&diferenca, conjuntoA.elementos[i]);
        }
    }

    for (int i = 0; i < conjuntoB.tamanho; i++) {
        int encontrado = 0;
        for (int j = 0; j < conjuntoA.tamanho; j++) {
            if (conjuntoB.elementos[i] == conjuntoA.elementos[j]) {
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            adicionarElemento(&diferenca, conjuntoB.elementos[i]);
        }
    }

    printf("Diferença Simétrica: ");
    imprimirConjunto(diferenca);
}

void potenciaConjunto(Conjunto conjunto) {
    int tamanhoPotencia = pow(2, conjunto.tamanho);

    printf("Potência do Conjunto: \n");
    for (int i = 0; i < tamanhoPotencia; i++) {
        printf("{ ");
        for (int j = 0; j < conjunto.tamanho; j++) {
            if (i & (1 << j)) {
                printf("%d ", conjunto.elementos[j]);
            }
        }
        printf("}\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Conjunto conjuntoA, conjuntoB;
    inicializarConjunto(&conjuntoA);
    inicializarConjunto(&conjuntoB);

    // Adicionando elementos ao conjunto A
    adicionarElemento(&conjuntoA, 4);
    adicionarElemento(&conjuntoA, 7);
    adicionarElemento(&conjuntoA, 8);

    // Adicionando elementos ao conjunto B
    adicionarElemento(&conjuntoB, 4);
    adicionarElemento(&conjuntoB, 9);
    adicionarElemento(&conjuntoB, 10);
    adicionarElemento(&conjuntoB, 8);

    // Imprimindo os conjuntos A e B
    printf("Conjunto A: ");
    imprimirConjunto(conjuntoA);

    printf("Conjunto B: ");
    imprimirConjunto(conjuntoB);
    printf("\n");

    // Mostrando o complemento universal
    complementoUniversal(conjuntoA);
    printf("\n");

    // Mostrando a diferença simétrica
    diferencaSimetrica(conjuntoA, conjuntoB);
    printf("\n");

    // Mostrando a potência dos conjuntos
    printf("Potência do Conjunto A:\n");
    potenciaConjunto(conjuntoA);
    printf("\n");

    printf("Potência do Conjunto B:\n");
    potenciaConjunto(conjuntoB);
    printf("\n");

    return 0;
}