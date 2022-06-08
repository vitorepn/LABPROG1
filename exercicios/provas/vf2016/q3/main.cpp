#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

struct Pessoa{
    string nome;
    int idade;
    Pessoa(string nome, int idade):nome(nome),idade(idade){}
};

bool gravar(vector<Pessoa>& v,string nomeDoArquivo){
    ofstream arquivo;
    auto it{v.begin()};
    arquivo.open(nomeDoArquivo,ios::binary);
    while(it!= v.end()){
        arquivo.write((char*)& it,sizeof(Pessoa));
        it++;
    }
    arquivo.close();
    
}

bool carregar(vector<Pessoa>& v, string nomeDoArquivo){
    ifstream arquivo;
    arquivo.open(nomeDoArquivo,ios::binary);
    arquivo.read((char*)& v, sizeof(Pessoa));
    arquivo.close();

}


int main(){
    vector<Pessoa> vetor1;
    vector<Pessoa> vetor2;
    vetor1.push_back(Pessoa("fulano",3));
    vetor1.push_back(Pessoa("eu",5));
    gravar(vetor1,"saida.txt");
    carregar(vetor2,"saida.txt");
    auto it{vetor2.end()};
    cout<<vetor2.size();

}