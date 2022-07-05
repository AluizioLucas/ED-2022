#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <numeric>
#include <functional>
#include <sstream>

using namespace std;

const char EMPTY = '.';

template<class T>
    vector<T> range(T begin, T end) {
        vector<T> result;
        for (T i = begin; i < end; i++) {
            result.push_back(i);
        }
        return result;
    }

struct Problema {
    string data;
    int lim;
    vector<int> holes;

    Problema(string data, int lim) {
        this->data = data;
        this->lim = lim;
        for (int i = 0; i < data.size(); i++) 
            if (data[i] == EMPTY) 
                holes.push_back(i);
    }

    bool fit(int pos, int size) {
        for (int i = pos; i < pos + size; i++) {
            if (i >= data.size() || data[i] != EMPTY)
                return false;
        }
        return true;
    }

    bool solve(int hindex) {
        if (hindex == holes.size()) {
            return true;
    }

    auto index = holes[hindex];

    for (int size = 1; size <= lim; size++) {
        if (fit(index, size)) {
            data[index] = size;
            if (solve(hindex + 1))
                return true;
            data[index] = EMPTY;
        }
    }

    return false;

    }   
};

    int main () {
        int n, m;
        cin >> n >> m;
        string data(n, EMPTY);
        cin >> data;
        Problema p(data, m);
        p.solve(0);
        cout << data << endl;
    }