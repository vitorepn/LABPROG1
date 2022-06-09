#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<math.h> 

using namespace std;

class Image{
    public:
    vector<vector<bool>> matriz;
    int tamanho;
    
    Image():tamanho(0){};
    void leitura(string caminho){
        int contador = 0,linha = 0,coluna=0;
        ifstream arquivo;
        string frase;
        arquivo.open(caminho);
        if(!arquivo.is_open()){
            cout<<"Erro na leitura do arquivo"<<endl;
            return;
        }
        getline(arquivo,frase);
        tamanho = stoi(frase);
        getline(arquivo,frase);
        for(int i = 0;i<tamanho;i++){
            matriz.push_back(vector<bool>(0,0));
        }
        cout<<matriz.size();
        while(contador<pow(tamanho,2)){
            vector<bool> temp;
            if(frase[contador]=='1'){
                matriz[linha].push_back(true);
            }else{
                matriz[linha].push_back(false);
            }
            contador++;
            coluna++;
            if(coluna==tamanho){
                matriz.push_back(temp);
                coluna = 0;
                linha ++;
            }
        }
    }
    void imprimir(){
        for(int linha =0;linha<tamanho;linha++){
            for(int coluna = 0; coluna<tamanho;coluna++){
                if(matriz[linha][coluna]==true){
                    cout<<char(219);
                }else{
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }
};

int main(){
    Image im1;
    im1.leitura("texto.img");
    cout<<endl;
    cout<<endl;
    im1.imprimir();

}