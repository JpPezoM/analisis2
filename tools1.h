//Funciones varias para trbajar los vectores usados en la sol1 y sol2
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

//imprime vector de enteros
void printVector(vector<int> &lol){
    printf("(");
    for(int l: lol) printf("%i ", l);
    printf(")\n");
}

//Lo mismo pero con vector de bool
void printVector(vector<bool> &lol){
    printf("(");
    for(bool l: lol) l ? printf("1") : printf("0");
    printf(")\n");
}

//reinicia los valores del vector auxiliar a false, tiempo n
void restartVector(vector<bool> &v, int n){
    for(int i = 0; i < n; i++){
        v[i] = false;
    }
}

//Asumimos como solucion inicial que el MSC es toda la familia de conjuntos, tiempo n
void initVector(vector<int> &v, int n){
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
}

//comprueba que la union de conjuntos sea setCover i.e., tiempo n (mejorable)
bool setCover(vector<bool> &v, int n){
    bool b = true;
    for(int i = 0; i < n; i++){
        if(not v[i]) b = false;
    }
    return b;
}

//Inicializa los valores del arreglo en 1000... i.e. tomar el primer elemento 
void initCombi(vector<bool> &b){
    b[0] = true;
    for(int i= 1; i < b.size(); i++){
        b[i] = false;
    }
}

//Mueve el arreglo a la siguiente combinacion de conjuntos
void plusOne(vector<bool> &b){
    int c = 0;
    while(b[c] and c < b.size()){
        b[c] = false;
        c += 1;
    }
    if(c <= b.size()) b[c] = true;
    
}

//encuentra todas las filas(sets) con elementos que no estan en otros sets
set<int> uniqueElem(int m, int n, vector<bool> &matrix){
    set<int> unique;
    int found, pos, j;
    for(int i = 0; i < n; i++){
        found = 0;
        pos= 0;
        j = i;
        while(j < (m*n) and found < 2){
            if(matrix[j]){
                found += 1;
                pos = j / n;
            }
            j += n;
        }
        if(found == 1) unique.insert(pos);
    }
    return unique;
}