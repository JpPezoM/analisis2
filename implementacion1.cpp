//Min Set Cover(Unicost) Metodo Exhaustivo O(2^N * m)
//Recibe una matriz binaria y entrega un subconjunto de filas tal que cubren todas las columnas con al menos un 1
//TODO programar la lectura/conversion de la entrada y quitar un poco de for-loop's

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include "vectorTools.h"
using namespace std;


vector<int> exhaustiveSearch(int m, int n, vector<bool> &matrix){
    vector<int> result(m);//msc mas pequeño encontrado hasta el momento
    vector<bool> aux(n); //elementos añadidos en cada instante
    vector<bool> combi(m); //vector de ayuda para calcular las combinaciones
    int c = 1; 
    initCombi(combi);
    initVector(result, m);

    //testea todas las 2^m combinaciones distintas de sets
    for(int i = 0; i < pow(2,m) - 1; i++){
        c = 0;
        restartVector(aux, n);
        for(int j = 0; j <= n; j++){
            if(combi[j]){
                //Añade la fila al aux
                for(int l = 0; l < n; l++){
                aux[l] = aux[l] or matrix[(j * n) + l];
                }
                c++;
            }
        }
        if(setCover(aux, n) and result.size() > c){
            result.clear();
            for(int k = 0; k < n; k++){
                if(combi[k]) result.push_back(k);
            }
        }
        plusOne(combi);
    }
    return result;
}

int main(){
    vector<bool> carlos(6*12); // matriz de prueba
    carlos = 
    {
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 
        1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
        0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1
    };

    vector<int> msc;
    msc = exhaustiveSearch(6, 12, carlos);
    printf("el minimum set cover es de tamaño: ");
    cout << msc.size() << endl;
    printVector(msc);
    return 0;
}