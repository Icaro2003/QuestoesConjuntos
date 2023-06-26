#include <stdio.h>
#include <locale.h>

// Fun��o para verificar a interse��o entre os conjuntos A e B
void intersecao(int A[], int tamanhoA, int B[], int tamanhoB) {
    int i, j;
    int encontrouIntersecao = 0;
    printf("Interse��o: ");
    for (i = 0; i < tamanhoA; i++) {
        for (j = 0; j < tamanhoB; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                encontrouIntersecao = 1;
                break;
            }
        }
    }
    if (!encontrouIntersecao) {
        printf("N�o h� interse��o.");
    }
    printf("\n");
}

// Fun��o para calcular a cardinalidade de um conjunto
int cardinalidade(int conjunto[], int tamanho) {
    return tamanho;
}

// Fun��o para unir os conjuntos A e B
void uniao(int A[], int tamanhoA, int B[], int tamanhoB) {
    int i, j;
    int C[100];
    int tamanhoC = 0;
    for (i = 0; i < tamanhoA; i++) {
        C[tamanhoC] = A[i];
        tamanhoC++;
    }
    for (j = 0; j < tamanhoB; j++) {
        int elementoJaPresente = 0;

        for (i = 0; i < tamanhoA; i++) {
            if (B[j] == A[i]) {
                elementoJaPresente = 1;
                break;
            }
        }
        if (!elementoJaPresente) {
            C[tamanhoC] = B[j];
            tamanhoC++;
        }
    }
    printf("Uni�o: ");
    for (i = 0; i < tamanhoC; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    int A[4] = {1, 4, 5, 7};
    int tamanhoA = sizeof(A) / sizeof(A[0]);
    int B[4] = {2, 4, 6, 8};
    int tamanhoB = sizeof(B) / sizeof(B[0]);
    printf("Conjunto A: ");
    for (int i = 0; i < tamanhoA; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Conjunto B: ");
    for (int i = 0; i < tamanhoB; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");

    intersecao(A, tamanhoA, B, tamanhoB);
    printf("Cardinalidade de A: %d\n", cardinalidade(A, tamanhoA));
    printf("Cardinalidade de B: %d\n", cardinalidade(B, tamanhoB));
    uniao(A, tamanhoA, B, tamanhoB);
    return 0;
}
