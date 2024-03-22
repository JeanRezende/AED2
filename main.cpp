#include <iostream>
#include <clocale>  //biblioteca de internalização
#include "biblio.h" //cabeçalho estatico criado

using namespace std;

int main()
{
    setlocale(LC_ALL,"Portuguese"); //usando a biblioteca clocale de internalização

    //declaração das instancias das structs criadas
    TFila clientes;
    TArvore cardapio;
    TPilhaP pilha;
    //inicialização das instancias
    criarPilhaPVazia(pilha);
    iniciarArvore(cardapio);
    criarFilaVazia(clientes);
    //lendo o arquivo que contem o cardapio
    lendoTItem("CardapioArvore.txt",5,cardapio);
    //chamando a função de interação com o usuario
    interacaouser(cardapio, clientes, pilha);
    return 0;
}
