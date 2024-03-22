#include <iostream>
#include <clocale>  //biblioteca de internaliza��o
#include "biblio.h" //cabe�alho estatico criado

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese"); //usando a biblioteca clocale de internaliza��o

    //declara��o das instancias das structs criadas
    TFila clientes;
    TArvore cardapio;
    TPilhaP pilha;
    //inicializa��o das instancias
    criarPilhaPVazia(pilha);
    iniciarArvore(cardapio);
    criarFilaVazia(clientes);
    //lendo o arquivo que contem o cardapio
    lendoTItem("CardapioArvore.txt",5,cardapio);
    //chamando a fun��o de intera��o com o usuario
    interacaouser(cardapio, clientes, pilha);
    return 0;
}
