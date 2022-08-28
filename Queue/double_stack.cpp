#include <iostream>
#include <list>
#include <stack>

using namespace std;

void coloca_prateleira(stack<int> &caixa, stack<int> &estante) {
    while (caixa.size() > 0) {
        estante.push(caixa.top());
        caixa.pop();
    }
}

void result(list<int> mostrar){
    cout << "---RESULT---" << endl;
    
    for (auto x : mostrar) {
        cout <<"[ ";
        cout << x ;
        cout << " ]" << endl;
    }
    

}

int main() {
    int tamanho, funcao, itens;

    stack<int> estante{}, caixa{};

    cin >> tamanho;

    list<int> mostrar {};

    for (int i = 0; i < tamanho; i++) {
        cin >> funcao;

        if (funcao == 1) {
            cin >> itens;
            caixa.push(itens);
        } 

        else if (funcao == 2) {
            if (estante.size() == 0) coloca_prateleira(caixa, estante);
            estante.pop();
        }
        
        else if (funcao == 3) {
            if (estante.size() == 0) coloca_prateleira(caixa, estante); mostrar.push_back(estante.top());    
        }
    }
    
    result(mostrar);
    
    return 0;
}