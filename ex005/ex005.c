#include <stdio.h>
#include <locale.h>

typedef struct
{
    int elementos[10];
    int tamanho;
} Conjunto;

void inicializarConjunto(Conjunto *conjunto)
{
    conjunto->tamanho = 0;
}

void adicionarAoConjunto(Conjunto *conjunto, int elemento)
{
    if (conjunto->tamanho < 10)
    {
        conjunto->elementos[conjunto->tamanho] = elemento;
        conjunto->tamanho++;
    }
}

void imprimirConjunto(Conjunto conjunto)
{
    printf("{ ");
    for (int i = 0; i < conjunto.tamanho; i++)
    {
        printf("%d ", conjunto.elementos[i]);
    }
    printf("}\n");
}

int estaNoConjunto(Conjunto conjunto, int elemento)
{
    for (int i = 0; i < conjunto.tamanho; i++)
    {
        if (conjunto.elementos[i] == elemento)
        {
            return 1;
        }
    }
    return 0;
}

void inclusaoExclusao(Conjunto conjuntoA, Conjunto conjuntoB)
{
    Conjunto conjuntoUniao;
    inicializarConjunto(&conjuntoUniao);

    Conjunto conjuntoIntersecao;
    inicializarConjunto(&conjuntoIntersecao);

    // União dos conjuntos A e B
    for (int i = 0; i < conjuntoA.tamanho; i++)
    {
        adicionarAoConjunto(&conjuntoUniao, conjuntoA.elementos[i]);
    }

    for (int i = 0; i < conjuntoB.tamanho; i++)
    {
        if (!estaNoConjunto(conjuntoA, conjuntoB.elementos[i]))
        {
            adicionarAoConjunto(&conjuntoUniao, conjuntoB.elementos[i]);
        }
        else
        {
            adicionarAoConjunto(&conjuntoIntersecao, conjuntoB.elementos[i]);
        }
    }

    // Exclusão dos elementos da interseção
    for (int i = 0; i < conjuntoIntersecao.tamanho; i++)
    {
        int elemento = conjuntoIntersecao.elementos[i];
        int indice = 0;
        while (indice < conjuntoUniao.tamanho)
        {
            if (conjuntoUniao.elementos[indice] == elemento)
            {
                // Remove o elemento da união
                for (int j = indice; j < conjuntoUniao.tamanho - 1; j++)
                {
                    conjuntoUniao.elementos[j] = conjuntoUniao.elementos[j + 1];
                }
                conjuntoUniao.tamanho--;
            }
            else
            {
                indice++;
            }
        }
    }

    printf("União dos conjuntos: ");
    imprimirConjunto(conjuntoUniao);
    printf("Interseção dos conjuntos: ");
    imprimirConjunto(conjuntoIntersecao);
}

void adicaoMultiplicacao(Conjunto conjuntoA, Conjunto conjuntoB)
{
    int adicao = conjuntoA.tamanho + conjuntoB.tamanho;
    int multiplicacao = conjuntoA.tamanho * conjuntoB.tamanho;

    printf("Adição dos tamanhos dos conjuntos: %d\n", adicao);
    printf("Multiplicação dos tamanhos dos conjuntos: %d\n", multiplicacao);
}

int saoDisjuntos(Conjunto conjuntoA, Conjunto conjuntoB)
{
    for (int i = 0; i < conjuntoA.tamanho; i++)
    {
        if (estaNoConjunto(conjuntoB, conjuntoA.elementos[i]))
        {
            return 0; // Os conjuntos não são disjuntos
        }
    }
    return 1; // Os conjuntos são disjuntos
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Conjunto conjuntoA;
    Conjunto conjuntoB;

    inicializarConjunto(&conjuntoA);
    inicializarConjunto(&conjuntoB);

    // Adicionando elementos ao conjunto A
    adicionarAoConjunto(&conjuntoA, 1);
    adicionarAoConjunto(&conjuntoA, 2);
    adicionarAoConjunto(&conjuntoA, 3);

    // Adicionando elementos ao conjunto B
    adicionarAoConjunto(&conjuntoB, 3);
    adicionarAoConjunto(&conjuntoB, 4);
    adicionarAoConjunto(&conjuntoB, 5);

    printf("Conjunto A: ");
    imprimirConjunto(conjuntoA);

    printf("Conjunto B: ");
    imprimirConjunto(conjuntoB);

    inclusaoExclusao(conjuntoA, conjuntoB);
    adicaoMultiplicacao(conjuntoA, conjuntoB);

    if (saoDisjuntos(conjuntoA, conjuntoB))
    {
        printf("Os conjuntos A e B são disjuntos.\n");
    }
    else
    {
        printf("Os conjuntos A e B não são disjuntos.\n");
    }

    return 0;
}