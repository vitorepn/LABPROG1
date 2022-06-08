#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

int main(){
    ifstream file{"arquivo.txt"};
    vector<char> codigo;
    string strInput;
    int tamanho;
    getline(file, strInput);
    tamanho = stoi(strInput);
    getline(file, strInput);
    for(int i = 0;i<strInput.size();i++){
        codigo.push_back(strInput[i]);
    }
    cout<<"a";
}