#include <iostream>
#include "biblio.h"

using namespace std;


void criarPilhaPVazia(TPilhaP &p){
    p.topo = new TCelula;
    p.fundo = p.topo;
    p.topo->proximo = NULL;
    p.cont = 0;
}

bool estaVaziaPilhaP (TPilhaP p){
    return p.topo == p.fundo;
}

void empilharPilhaP(TItem x, TPilhaP &p){
    TCelula *celAux = new TCelula;
    p.topo->item = x;
    celAux->proximo = p.topo;
    p.topo = celAux;
    p.cont++;
}

void desempilharPilhaP(TPilhaP &p){

    if (estaVaziaPilhaP(p)){
        cout << "Pilha vazia. Nenhum item para desempilhar!" << endl;
    }
    else{
        TCelula *pCelAux = p.topo; // cria a celAux e pega o valor de topo
        p.topo = p.topo->proximo;
        delete pCelAux;
        p.cont--;
    }
}
