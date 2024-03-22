#include <iostream>
#include <fstream>
#include "biblio.h"

using namespace std;

void iniciarArvore(TArvore &a){ //inicialização da arvore
    a.raiz = NULL;
    a.contador=0;
}

bool estaVazia(TArvore a){ //teste de arvore vazia
    return a.raiz == NULL;
}

void inserirArvore(TItem i, TNoh *&n, TArvore &a){ //insersao na arvore

     if (n == NULL){   // se o noh recebido estiver vazio insere
        n = new TNoh;
        n->item = i;
        n->esq = NULL;
        n->dir = NULL;
        if (a.raiz == NULL){ //para primeira inserção
            a.raiz = n;
        };
        a.contador++;
    }
    else{ //senao percorre e usa a recursividade ate achar um noh vazio, ou existir um valor igual na arvore
        if (i.codigo < n->item.codigo){
            inserirArvore(i,n->esq,a);
        }
            else{
            if (i.codigo > n->item.codigo){
                inserirArvore(i,n->dir,a);
                }
                else{
                cout << "Valor já existe na árvore!";
                }
            }
        }
}

void percorrerINOrdem(TNoh *&a){
    if(a!=NULL){
        percorrerINOrdem(a->esq);
        cout << a->item.codigo << ", ";
        percorrerINOrdem(a->dir);
    }
}

void percorrerPREOrdem(TNoh *&a){
    if(a!=NULL){
        cout << a->item.codigo << ", ";
        percorrerPREOrdem(a->esq);
        percorrerPREOrdem(a->dir);
    }
}

void percorrerPOSOrdem(TNoh *&a){
    if(a!=NULL){
        percorrerPOSOrdem(a->esq);
        percorrerPOSOrdem(a->dir);
        cout << a->item.codigo << ", ";
    }
}

void pesquisar(TItem i, TNoh *&n, TArvore a, TFila &f){ //função que pesquisa o item no cardapio, pelo codigo do produto
    // e transfere da arvore para a fila

    if (n == NULL){
        cout << "Registro não localizado na árvore" << endl;
    }
    else { //busca pela chave fornecida
        if (i.codigo < n->item.codigo){
            pesquisar(i, n->esq, a, f);
        }
        else {
            if (i.codigo > n->item.codigo){
                pesquisar(i, n->dir, a, f);
            }
            else{

                inserirFila(n->item,f); //insere na fila
            }
        }
    }
}
///
void pegarAnterior(TNoh *q, TNoh *&r){

    if (r->dir != NULL){
        pegarAnterior(q, r->dir);
    }
    else{
        q->item = r->item;
        q = r;
        r = r->esq;
        delete q;
    }
}
///
void retirar(TItem i, TNoh *&p){
TNoh *aux;

    if (p == NULL){
        cout << "Registro não encontrado" << endl;
    }
    else{
        if (i.codigo < p->item.codigo){
            retirar(i, p->esq);
        }
        else{
            if (i.codigo > p->item.codigo){
                retirar(i, p->dir);
            }
            else{
                if (p->dir == NULL){
                    aux = p;
                    //exemplo de "debug manual" para ajudar a entender o código
                    //cout << "Passada Dir: " << aux->item.codigo << endl;
                    p = p->esq;
                    delete aux;
                }
                else{
                    if (p->esq != NULL){
                        pegarAnterior(p, p->esq);
                    }
                    else{
                        aux = p;
                        p = p->dir;
                        delete aux;

                    }
                }
            }
        }
    }
}
