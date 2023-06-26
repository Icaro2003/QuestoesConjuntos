#include <stdio.h>

#define TAMANHO_MAXIMO 10

typedef struct
{
    int elementos[TAMANHO_MAXIMO];
    int tamanho;
} Conjunto;

void inicializarConjunto(Conjunto *conjunto)
{
    conjunto->tamanho = 0;
}

void adicionarAoConjunto(Conjunto *conjunto, int elemento)
{
    if (conjunto->tamanho >= TAMANHO_MAXIMO)
    {
        printf("Conjunto cheio. Não é possível adicionar mais elementos.\n");
        return;
    }

    conjunto->elementos[conjunto->tamanho] = elemento;
    conjunto->tamanho++;
}

int pertenceAoConjunto(Conjunto *conjunto, int elemento)
{
    for (int i = 0; i < conjunto->tamanho; i++)
    {
        if (conjunto->elementos[i] == elemento)
        {
            return 1;
        }
    }

    return 0;
}

int ehSubconjunto(Conjunto *conjuntoA, Conjunto *conjuntoB)
{
    for (int i = 0; i < conjuntoA->tamanho; i++)
    {
        if (!pertenceAoConjunto(conjuntoB, conjuntoA->elementos[i]))
        {
            return 0;
        }
    }
    return 1;
}

void uniaoConjunto(Conjunto *conjuntoA, Conjunto *conjuntoB)
{
    Conjunto conjuntoUniao;
    inicializarConjunto(&conjuntoUniao);

    for (int i = 0; i < conjuntoA->tamanho; i++)
    {
        adicionarAoConjunto(&conjuntoUniao, conjuntoA->elementos[i]);
    }

    for (int i = 0; i < conjuntoB->tamanho; i++)
    {
        if (!pertenceAoConjunto(&conjuntoUniao, conjuntoB->elementos[i]))
        {
            adicionarAoConjunto(&conjuntoUniao, conjuntoB->elementos[i]);
        }
    }

    printf("União dos conjuntos A e B: ");
    for (int i = 0; i < conjuntoUniao.tamanho; i++)
    {
        printf("%d ", conjuntoUniao.elementos[i]);
    }
    printf("\n\n");
}

void intersecaoConjunto(Conjunto *conjuntoA, Conjunto *conjuntoB)
{
    Conjunto conjuntoIntersecao;
    inicializarConjunto(&conjuntoIntersecao);

    for (int i = 0; i < conjuntoA->tamanho; i++)
    {
        if (pertenceAoConjunto(conjuntoB, conjuntoA->elementos[i]))
        {
            adicionarAoConjunto(&conjuntoIntersecao, conjuntoA->elementos[i]);
        }
    }

    printf("Interseção dos conjuntos A e B: ");
    for (int i = 0; i < conjuntoIntersecao.tamanho; i++)
    {
        printf("%d ", conjuntoIntersecao.elementos[i]);
    }
    printf("\n\n");
}

int calcularCardinalidade(Conjunto *conjunto)
{
    return conjunto->tamanho;
}

void lerElementosConjunto(Conjunto *conjunto)
{
    int quantidade, elemento;

    printf("Digite a quantidade de elementos para o conjunto: ");
    scanf("%d", &quantidade);

    printf("Digite os elementos do conjunto:\n");
    for (int i = 0; i < quantidade; i++)
    {
        scanf("%d", &elemento);
        adicionarAoConjunto(conjunto, elemento);
    }
}

void imprimirConjunto(Conjunto *conjunto)
{
    printf("Elementos do conjunto: ");
    for (int i = 0; i < conjunto->tamanho; i++)
    {
        printf("%d ", conjunto->elementos[i]);
    }
    printf("\n\n");
}

int main()
{
    Conjunto conjuntoA, conjuntoB;
    int elemento;

    inicializarConjunto(&conjuntoA);
    inicializarConjunto(&conjuntoB);

    printf("Conjunto A:\n\n");
    lerElementosConjunto(&conjuntoA);
    imprimirConjunto(&conjuntoA);

    printf("Conjunto B:\n\n");
    lerElementosConjunto(&conjuntoB);
    imprimirConjunto(&conjuntoB);

    // Verifique a pertinência dos elementos e imprima na tela
    printf("Verificar a pertinência no conjunto A : ");
    scanf("%d", &elemento);

    if (pertenceAoConjunto(&conjuntoA, elemento))
    {
        printf("%d pertence ao conjunto A: VERDADEIRO\n\n", elemento);
    }
    else
    {
        printf("%d pertence ao conjunto A: FALSO\n\n", elemento);
    }

    printf("Verificar a pertinência no conjunto B : ");
    scanf("%d", &elemento);

    if (pertenceAoConjunto(&conjuntoB, elemento))
    {
        printf("%d pertence ao conjunto B: VERDADEIRO\n\n", elemento);
    }
    else
    {
        printf("%d pertence ao conjunto B: FALSO\n\n", elemento);
    }

    if (ehSubconjunto(&conjuntoA, &conjuntoB))
    {
        printf("O conjunto A é subconjunto do conjunto B: VERDADEIRO\n\n");
    }
    else
    {
        printf("O conjunto A é subconjunto do conjunto B: FALSO\n\n");
    }

    // União dos conjuntos A e B
    uniaoConjunto(&conjuntoA, &conjuntoB);

    // Interseção dos conjuntos A e B
    intersecaoConjunto(&conjuntoA, &conjuntoB);

    // Cardinalidade dos conjuntos A e B
    printf("Cardinalidade do conjunto A: %d\n", calcularCardinalidade(&conjuntoA));
    printf("Cardinalidade do conjunto B: %d\n", calcularCardinalidade(&conjuntoB));

    return 0;
}