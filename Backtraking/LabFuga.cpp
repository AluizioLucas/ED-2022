#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

bool completar(string Linha, int Indice, int Limite, int Proximidade){
    if((int) Linha.size() == Indice) return false;

    if(Linha [Indice] != '.') return completar(Linha, Indice + 1, Limite, Proximidade);

    for(int valor = 0; valor <= Limite; valor++){
        if(adicionar(Linha, Indice, valor, Proximidade)) return true;
    }

    Linha[Indice] = '.';
    cout << Linha;
    cout << endl;
    return false;
}

bool adicionar(string& Linha, int Indice, int Valor, int Proximidade){
    for(int i { Indice + 1}; i < Indice + 1 + Proximidade; i++){
        if(i < (int) Linha.size() && Linha[i] == Valor + '0') return false;
    }
    return true;
}

int main(){
    string Linha;
    
    int Limite{1}, Proximidade{0};
    ifstream In("input.txt");
    In >> Linha >> Proximidade;

    completar(Linha, 0, Limite, Proximidade);
}