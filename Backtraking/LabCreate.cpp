#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void Breach(vector<string>& matriz, local posi){
    int l = posi.linha, c = posi.coluna;
    if(borda(matriz, posi)) return;
    if(matriz[l][c] != '#') return;
    if(!perfurar(matriz, posi)) return;
    matriz[l][c] = '.';
    ShowMatriz(matriz);
    for(auto kar : Embaralhar(proximos(posi))) perfurar(matriz, kar);
}

bool perfurar(vector<string>& matriz, local posi){
    int aux = 0;
    for(auto kar : proximos(posi)) {
        if(borda(matriz, kar)) continue;
        if(matriz[kar.linha][kar.coluna] == '#') aux += 1; 
    } 
    return (aux >= 3);
}

struct local{
   int linha;
   int coluna;
   local(int linha, int coluna): linha(linha), coluna(coluna){}
};

vector<local> proximos(local posi){
    int l = posi.linha, c = posi.coluna;
    return {{l, c - 1}, {l, c + 1}, {l - 1, c}, {l + 1, c}};
}

bool borda(vector<string>& matriz, local posi) {
    int l = posi.linha, c = posi.coluna;
    int numl = matriz.size(), numc = matriz[0].size();
    if (l < 0 || l >= numl || c < 0 || c >= numc) return true;
    return false;
}

vector<local> Embaralhar(vector<local> vet) {
    random_shuffle(begin(vet), end(vet));
    return vet;
}

void ShowMatriz(vector<string>& matriz) {
    for (auto l : matriz) cout << l << endl;
    getchar();
}

int main(int argc, char * argv[]){
    if(argc != 3) exit(1);
    int numl{0}, numc{0};
    stringstream(argv[1]) >> numl; 
    stringstream(argv[2]) >> numc;
    vector<string> matriz(numl , string(numc, '#'));
    Breach(matriz, local(1, 1));
    ShowMatriz(matriz);
}