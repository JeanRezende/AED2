#include <iostream>
#include "biblio.h"

using namespace std;

/* Implementção generica de fila linear
    para uso como biblioteca */


///OPERAÇÕES DA LISTA LINEAR DUPLAMENTE ENCADEADA

void criarFilaVazia(TFila &f) //procedimento para iniciar uma fila
{
    f.inicio = new TCelula;
    f.fim = f.inicio;
    f.inicio->proximo = NULL;
    f.quantElementos = 0;
}

bool FilaVazia(TFila f)
{
    return f.inicio == f.fim;

}

void inserirFila(TItem x, TFila &f){ // inserção no final da fila

    f.fim->proximo = new TCelula;

    f.fim = f.fim->proximo;
    f.fim->item = x;
    f.fim->proximo = NULL;
    f.quantElementos++; //variavel para controlar a quantidade de elem na fila
}

void retirarDaFila(TFila &f) //FIFO
{
    TCelula *antItem;
    if(FilaVazia(f))
    {
        cout << "lista vazia, impossivel retirar" << endl;
    }else{
        antItem = f.inicio;
        f.inicio = f.inicio->proximo;

        f.quantElementos--;
        delete antItem;
    }
}
