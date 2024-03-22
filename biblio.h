#ifndef BIBLIO_H_INCLUDED
#define BIBLIO_H_INCLUDED

using namespace std;

/* Implementção generica de fila linear duplamente encadeada
    para uso como biblioteca */


///OPERAÇÕES DA LISTA LINEAR DUPLAMENTE ENCADEADA



//TAD
struct TItem
 {
    string produto;
    int codigo;
    float preco;
    float custo;
};
//celula da arvore
struct TNoh
{
    TItem item;
    TNoh *esq,*dir;
};
//celula estruturas lineares
struct TCelula
{
    TItem item;
    TCelula *proximo;
};
//estrutura da fila
struct TFila
{
    TCelula *inicio;
    TCelula *fim;
    int quantElementos;
};
//estrutura da pilha
struct TPilhaP{
    TCelula *topo;
    TCelula *fundo;
    int cont;
};
//estrutura da arvore
struct TArvore
{
    TNoh *raiz;
    int contador;
};

//assinaturas arvore binaria
void iniciarArvore(TArvore &a);
bool estaVazia(TArvore a);
void inserirArvore(TItem i, TNoh *&n, TArvore &a);
void percorrerINOrdem(TNoh *&a);
void percorrerPREOrdem(TNoh *&a);
void percorrerPOSOrdem(TNoh *&a);
void pesquisar(TItem i, TNoh *&n, TArvore a, TFila &f);
void pegarAnterior(TNoh *q, TNoh *&r);
void retirar(TItem i, TNoh *&p);

//assinaturas fila linear
void criarFilaVazia(TFila &f);
bool FilaVazia(TFila f);
void inserirFila(TItem x, TFila &f);
void retirarDaFila(TFila &f);

//assinaturas implementação da Fstream
int lendoTItem(string nomeArq, int quantTokens, TArvore &a);
int escrevendoArq(string nomeArq, string vetDados[], int quantTokens);

//assinaturas de implementações nao genericas
void pedido (TItem c,TArvore &a, TFila &f);
void interacaouser (TArvore &a, TFila &f, TPilhaP &p);
void percorrerINOrdemModif(TNoh *&a);
void mostrarArvore(TArvore a);

//assinaturas de implementações da Pilha por ponteiros
void criarPilhaPVazia(TPilhaP &p);
bool estaVaziaPilhaP (TPilhaP p);
void empilharPilhaP(TItem x, TPilhaP &p);
void mostrarPilhaP(TPilhaP p);
void desempilharPilhaP(TPilhaP &p);

#endif // BIBLIO_H_INCLUDED
