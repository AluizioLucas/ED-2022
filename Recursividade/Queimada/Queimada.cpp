#include <iostream>
#include <vector>

using namespace std;


void fogo_na_floresta(vector<string>& mapa, int n_l, int n_c){
    int l = mapa.size(), c = mapa[0].size();
    if(n_l >= l || n_l < 0 || n_c >= c || n_c < 0){
        return;
    } else if(mapa[n_l][n_c] != '#'){
        return;
    }

    mapa[n_l][n_c] = '*';

    fogo_na_floresta(mapa, n_l + 1, n_c);
    fogo_na_floresta(mapa, n_l - 1, n_c);
    fogo_na_floresta(mapa, n_l, n_c + 1);
    fogo_na_floresta(mapa, n_l, n_c - 1);
}

void print(vector<string>& mapa){
    cout << endl;
        for(auto line : mapa){

        cout << line << '\n';
    }
}

int main(){
    int  numero_coluna, numero_linha, fogo_na_coluna, fogo_na_linha; 

    cin >> numero_linha >> numero_coluna >> fogo_na_linha >> fogo_na_coluna;

    vector<string> mapa(numero_linha);

    for(int i = 0; i < numero_linha; i++){
        cin >> mapa[i];
    }

    fogo_na_floresta(mapa, fogo_na_linha, fogo_na_coluna);
    print(mapa);


    return 0;
}