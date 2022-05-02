#include <iostream>
#include <sstream>
using namespace std;

//double free corruption

struct Vector{
    int _capacity {0}; //esse {} é o modo de inicializar default do c++ a partir do c++11
    int _size {0};
    int * _data {nullptr}; //inicializar pra não conter lixo

    Vector(int capacity){
        _capacity = capacity;
        _size = capacity;
        new int[capacity];
    }

    void pop_back(){
        if(_size == 0){
            return;
        }
        _size -= 1;
    }

    int& at(int indice){
        if(indice < 0 || indice >= _size){
            throw string("indice invalido");
        }
        return _data[indice];
    }

    void reserve(int capacity){
        int * _new_data = new int[capacity];
        int qtd = min(_size, capacity);
        for (int i = 0; i < qtd; i++){
            _new_data[i] = _data[i];
        }
        _size = qtd;               //qtd de elementos do vetor
        _capacity = capacity;
        
        delete [] _data;           //devolve o bloco antigo
        _data = _new_data;         //atualiza a referencia
    }

    //como seu vector tem atritutos do tipo ponteiros, você precisa criar um
    //construtor de cópia e um operador de atribuição ou terá erros do tipo double-free

    //O operador de atribuição será invocado quando você fizer um Vector receber outro
    //Ex:
    //Vector vec(4);
    //vec = Vector(6);
    //nesse ponto, os atributos de this já foram inicializados, 
    //mas você precisa alterá-los para copiar os valores de other
    void operator = (const Vector& other){
        //inicialize this->capacity com other.capacity
        //inicialize this->size com other.size
        //se this->data não for nulo, devolva a memória com delete
        //crie nova memória para this->data do tamanho de other.capacity
        //copie os dados de other.data para this->data
    }

    //aqui você ensina seu vector a ser criado a partir de outro vector
    //Ex: 
    //Vector v(4);
    //Vector v2(v);
    Vector(Vector& other){
        //aqui você não precisa fazer nada, basta utilizar o operador de atribuição
        //que você já implementou
        *this = other;
    }
    ~Vector(){
        this->_data;
    }
    void add(int value){
        //se ainda couber, copia value para o novo valor
    }

    //esse é o toString do c++
    //tudo que enviar para os, é como se estivesse enviando para saída padrão
    //basta entender o funcionamento
    friend ostream& operator<<(ostream &os, Vector vector){
        os << "[ ";
        for(int i = 0; i < vector._size; i++)
            os << vector._data[i] << " ";
        os << "]";
        return os;
    }
};


/* NAO MEXA DAQUI PRA BAIXO */
int main(){
    string line, cmd;
    int value;
    Vector v(0);
    while(true){
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        } else if(cmd == "init"){
            ss >> value;
            v = Vector(value);
        } else if(cmd == "status"){
            cout << "size:" << v.size << " capacity:" << v.capacity << "\n";
        } else if(cmd == "add"){
            while(ss >> value)
                v.add(value);
        } else if(cmd == "show"){
            cout << v << endl;
        } else {
            cout << "fail: comando invalido\n";
        }
    }
}