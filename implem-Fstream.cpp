#include <iostream>
#include <fstream>
#include "biblio.h"
#include <stdlib.h> //biblioteca para usar a conversao de tipos

using namespace std;



// LENDO DO ARQUIVO E UTILIZANDO NA MEMÓRIA
int lendoTItem(string nomeArq, int quantTokens, TArvore &a){


    TItem Aux;
    int auxconver;
    fstream arq(nomeArq.c_str());// instanciando e abrindo o arquivo com modificações para reconhecimento de string

    if (arq.is_open()){ //teste se o arquivo esta aberto
        string registro, token;
        string valores[quantTokens];
        int i, j, contToken;  //, contRegistro;

        while (arq.good()){
            getline(arq,registro);
            if (registro.length() > 0){ //ignora linhas em branco
                token = ""; // limpa variavel que recebe os campos do registro

                for (j=0; j < quantTokens;j++){ // limpa as posicoes do vetor
                    valores[j] = token;
                }

                i=0;
                contToken=0;
                while (i <= int(registro.length())){  //percorrendo o vetor de registro
                   if (registro[i] != ';') {
                        token = token + registro[i]; //  preenchendo a variavel token( caractere a caractere)
                    }
                    else{
       //switch case foi necessario, pois cada item da estrutura é de um tipo
       //então torna a conversão mais facil
                       switch(contToken)
                       {
                            case 0: //nome do produto
                                Aux.produto = token; //tipo string, sem conversão
                                break;
                            case 1: //codigo do produto
                                auxconver = atoi(token.c_str()); //string para int
                                Aux.codigo = auxconver;
                                break;
                            case 2: //preço do  produto
                                auxconver = atof(token.c_str()); //string para float
                                Aux.preco = auxconver;
                                break;
                       }
                       contToken++;     // INCREMENTA O CONTTOKEN
                       token = "";   // LIMPA
                    }
                    i++;
                }
                //ultimo campo que nao tem ;
                auxconver = atof(token.c_str()); // string para float
                Aux.custo = auxconver;
                //insere 1 registro na arvaore
               inserirArvore(Aux, a.raiz, a);
            }
        }
    }
    else{
        cout << "Problemas com a abertura do arquivo!" << endl;
	return -1;
    }
    arq.close();
    return 0;
}

// PEGANDO DA MEMÓRIA E LEVANDO PARA O ARQUIVO
int escrevendoArq(string nomeArq, string vetDados[], int quantTokens){

    int i;
    string registro = "";
    fstream arquivo(nomeArq.c_str(),ios::ate|ios::in|ios::out);

    if (arquivo.is_open()){
        for (i=0; i<quantTokens;i++){   // MONTANDO NOSSO REGISTRO!
            if (i < quantTokens-1){
                registro = registro + vetDados[i] + ";";
            }
            else{
                registro = registro + vetDados[i] + "\n";
            }
        }
        arquivo << registro; // ESCREVE O REGISTRO NO ARQUIVO!
        arquivo.close();
        cout << "Dados inseridos com sucesso!" << endl;
        return 0;
    }
    else{
        cout << "Problemas com o arquivo!" << endl;
        return -1;
    }
}
