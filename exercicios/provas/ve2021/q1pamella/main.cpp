//VERSAO ARRAY
#include <iostream>

using namespace std;

enum modoDeque{
    frente = 0,
    retaguarda
};

class Deque {
    private:
        int maximo;
        int tamanho;
        int *deque;
    public:
        Deque(int n) : maximo(n), tamanho(0) {
            deque = new int[n];
        }
        Deque(const Deque &d): 
            maximo(d.maximo), tamanho(d.tamanho), deque(new int[maximo]) {
                for(int i=0; i<tamanho; i++){
                    deque[i]=d.deque[i];
                }
        };
        ~Deque() {
            delete [] deque;
        }
        void inserir(modoDeque modo, int valor) {
            if(tamanho == maximo){
                cout << "Deque completamente cheio" << endl;
            }
            else{
                if(modo == frente) {
                    int ultimo = deque[tamanho-1];
                    for(int i=tamanho -1; i>0; i--){
                        deque[i]=deque[i-1];
                    }
                    deque[tamanho++]=ultimo;
                    deque[0]=valor;
                }
                else{
                    deque[tamanho++]=valor;
                }
                cout << "Valor inserido: " << valor << endl;
            }
        }
        void remover(modoDeque modo){
            if(tamanho == 0){
                cout << "Deque vazio" << endl;
            }
            else {
                if(modo == frente){
                    int primeiro = deque[0];
                    for(int i=1; i<tamanho; i++){
                        deque[i-1]=deque[i];
                    }
                    tamanho--;
                    cout << "Valor removido: " << primeiro << endl;
                }
                else{
                    int ultimo = deque[tamanho -1];
                    tamanho--;
                    cout << "Valor removido: " << ultimo << endl;
                }
            }
            
        }
        void imprimir(){
            cout << "Deque/Fila: " << endl;
            for(int i=0; i<tamanho; i++){
                cout << deque[i] << ", ";
            }
            cout << endl;
        }
};

class Fila: Deque {
    public: 
        Fila(int n) : Deque(n) {
        }
        void inserir(int valor) {
            Deque::inserir(retaguarda, valor);
        }
        void remover(){
            Deque::remover(frente);
        }
        void imprimir(){
            Deque::imprimir();
        }

};


int main()
{
    // int maximo;
    // cout << "Insira o tamanho maximo do deque: ";
    // cin >> maximo;
	// Deque deque(maximo);
/*     Deque deque(4);
    deque.imprimir();
    deque.inserir(frente, 1);
    deque.imprimir();
    deque.inserir(frente, 2);
    deque.imprimir();
    deque.inserir(retaguarda, 3);
    deque.imprimir();
    deque.inserir(retaguarda, 4);
    deque.imprimir();
    deque.inserir(frente, 5);
    deque.imprimir();
    deque.remover(frente);
    deque.imprimir();
    deque.remover(retaguarda);
    deque.imprimir();
    deque.remover(frente);
    deque.imprimir();
    deque.remover(frente);
    deque.imprimir();
    deque.remover(retaguarda);
    deque.imprimir();
 */
    Fila fila(4);
    fila.imprimir();
    fila.inserir(1);
    fila.imprimir();
    fila.inserir(2);
    fila.imprimir();
    fila.inserir(3);
    fila.imprimir();
    fila.inserir(4);
    fila.imprimir();
    fila.inserir(5);
    fila.imprimir();
    fila.remover();
    fila.imprimir();
    fila.remover();
    fila.imprimir();
    fila.remover();
    fila.imprimir();
    fila.remover();
    fila.imprimir();
    fila.remover();
    fila.imprimir();

	return 0;
}