#include<iostream>
#include <sstream>
#include <fstream>
#include <string.h>

using namespace std;

struct MultiStrings{
    char nome1[20];
    string nome2;
    ostringstream nome3;
};

bool salvabin(MultiStrings &ms, char *nome){
    ofstream arq(nome);
    int tamanho;

    if(!arq.is_open()){
        return false;
    }

    tamanho = strlen(ms.nome1);
    arq.write((char*)&tamanho,sizeof(int));
    arq.write(ms.nome1,tamanho);

    tamanho = strlen(ms.nome2.c_str());
    arq.write((char*)&tamanho,sizeof(int));
    arq.write(ms.nome2.c_str(),tamanho);

    tamanho = strlen(ms.nome3.str().c_str());
    arq.write((char*)&tamanho,sizeof(int));
    arq.write(ms.nome3.str().c_str(),tamanho);
}

bool carregabin(MultiStrings &ms, char *nome){
    ifstream arq(nome);
    int tamanho;
    char *temp;

    if(!arq.is_open()){
        return false;
    }

    for(int i = 0; i<3 ; i++){
        arq.read((char*)&tamanho,sizeof(int));
        temp = new char[tamanho+1];
        arq.read(temp,tamanho);
        if(!arq.good()){
            return false;
        }
        temp[tamanho] = '\0';
        switch(i){
            case 0:
                strcpy(ms.nome1,temp);
                break;
            case 1:
                ms.nome2 = temp;
                break;
            case 2:
                ms.nome3 << temp;
                break;
        }

    }
    arq.close();
    return true;
}

int main(){
    MultiStrings ms;
    strcpy(ms.nome1,"Primeira coisa");
    ms.nome2 = "Segunda coisa";
    ms.nome3.str("Terceira coisa");
    char *arquivo = new char[10];
    strcpy(arquivo,"saida.txt");
    salvabin(ms, arquivo);
}