#include <iostream>
#include <stack>
#include "biblio.h"

using namespace std;

void percorrerINOrdemModif(TNoh *&a){ //modifica��o do percorrerIN ordem da arvore
    //para mostrar os itens do cardapio
        if(a!=NULL){
        percorrerINOrdemModif(a->esq);
        cout << a->item.codigo  << '\t' << a->item.produto << '\t' <<  a->item.preco << endl;
        percorrerINOrdemModif(a->dir);
    }
}

void mostrarPilhaP(TPilhaP p){ //opera��o pra mostrar a pilha
    TCelula *pCelAux; //variavel para percorrer a pilha
    int i=0; //variavel para mostrar o numero do pedido

    pCelAux = p.topo->proximo;

    if(estaVaziaPilhaP(p))
    {
        cout << "Nenhum pedido ainda foi feito" << endl;
    }else{
        cout << "PEDIDO" << '\t' << " PRODUTO" << endl;
        while (pCelAux != NULL)
        {
            cout << i << '\t' << pCelAux->item.produto << endl;
            pCelAux = pCelAux->proximo;
            i++;
        }
    }
}

void mostrarArvore(TArvore a){ //mostrar arvore usando o percorrer em ordem modificado
    cout << endl << "-------------------------CARDAPIO-------------------------" << endl;
    cout << "C�DIGO" << '\t' << "PRODUTO" << '\t' << '\t' << "PRE�O(R$)" << endl;
    percorrerINOrdemModif(a.raiz);

    cout << endl << "----------------------------------------------------------" << endl;
}

void pedido (TArvore &a, TFila &f){//interface para o procedimento de intera��o para fazer o pedido
    TItem n;

    cout << "Digite o numero do pedido desejado     " ;
    cin >> n.codigo;
    cout << endl;
    if(n.codigo>0 && n.codigo<a.contador) //definindo range maximo pela quantidade de
    {                                       //itens no cardapio

    pesquisar(n, a.raiz, a, f); //pesquisando no cardapio e se achar insere na fila
    }else{
        cout << "Codigo de pedido inexistente" << endl;
    }
}

void balancoFinanceiro(TPilhaP p)   //fun��o que soma o preco e o custo, e calcula o lucro
{
    float preco,custo;
    TCelula *pCelAux;

    pCelAux = p.topo->proximo;

    cout << "======Balan�o Financeiro Total=====" << endl;
    cout << "preco" << '\t' << "custo" << '\t' << "lucro" << '\t' << "(R$)" << endl;
    if(estaVaziaPilhaP(p))
    {
        cout << "0" << '\t' << "0" << '\t' << "0" << endl;
    }else{
        while (pCelAux != NULL) //limite do percorrer, para nao passar do ultimo elem
        {
            preco = preco+pCelAux->item.preco; //somando pre�o
            custo = custo+pCelAux->item.custo;  //somando custo
            pCelAux = pCelAux->proximo; //passando o apontador para prox item
        }
    cout << preco << '\t' << custo << '\t' << preco-custo << endl; //resultado da fun��o
    }
}

void interacaouser (TArvore &a, TFila &f, TPilhaP &p) // intera��o com o usuario
{
    // variaveis definidas como auxiliares para usar as fun�oes
    string auxstr;
    int auxint, quant;
    float total=0.0;
    int j=1; //atribuindo valor pra nao ter problema no la�o de repeti��o


    while((j>0) && (j<4)){ //controle para loop e controle de saida
            cout << endl;
        cout << "=== Bom dia, o que deseja? ===" << endl;
        cout << "=======================================" << endl;
        cout << "1-" << "Ver o cardapio" << '\t';
        cout << "2-" << "Fazer o pedido" << endl;
        cout << "3-" << "MODO ADM" << '\t' ;
        cout << "4-" << "Fechar programa" << endl;

        cin >> j;
        switch(j)   //switch para menu
        {
        case 1: //para mostrar o cardapio, e ponte para fazer o pedido
            mostrarArvore(a);
            cout << "Deseja fazer o pedido?  s/n   " ;
            cin >> auxstr;
            cout << endl;
            if(auxstr!="s") //se nao desejar fazer o pedido break e volta ao menu
            {
                break;
            } //se digitar sim, passa direto para o caso 2
        case 2:
            pedido(a, f); //fun��o de fazer pedido
            cout << "Deseja fazer outro pedido?  s/n   ";
            cin >> auxstr;
            cout << endl;
            while(auxstr == "s") //loop para acrescimo de pedidos
            {
                pedido(a,f);
                    cout << "Deseja fazer outro pedido?  s/n   " ;
                    cin >> auxstr;
                    cout << endl;
            }
            if(FilaVazia(f)) //se nenhum pedido for feito
            {
                cout << "nenhum pedido feito, retornando ao menu!" << endl;
            }else{


                //fazendo a soma para retornar o pre�o total do pedido feito
                quant = f.quantElementos; //quant recebe f.quantelementos pois no la�o ele vai decrementar
                                        //com a retirada da fila
                for(auxint=0; auxint<quant; auxint++)
                {
                    total= total+f.inicio->proximo->item.preco; //somando o pre�o total para o usuario
                    //mostrando produtos escolhidos
                    cout <<  f.inicio->proximo->item.codigo << '\t' <<  f.inicio->proximo->item.produto << endl;
                    empilharPilhaP(f.inicio->proximo->item, p);   //o pedido � colocado na pilha, que recebe
                                                                //todos os pedidos ja feitos, para controle financeiro
                    retirarDaFila(f); //retirando da fila
                }
                cout << "Total = " << total  << "R$" << endl; //mostrando o pre�o total
                cout << "Retire seu pedido ao lado! " << endl;
            }
            break;
        case 3:
                cout << endl;
                cout << "==================MODO ADM==================" << endl;
                cout << "1-" << "Ver todos os pedidos ja feitos" << endl;
                cout << "2-" << "Ver balan�o financeiro" << endl;

                cin >> j;
            switch(j)
            {
                case 1:
                    mostrarPilhaP(p); //mostrando todos os pedidos ja feitos
                    break;
                case 2:
                    balancoFinanceiro(p); //mostrando o balan�o financeiro
                    break;
            }
            break;
        }
    }
}
