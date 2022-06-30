//Min Set Cover(Unicost) Metodo Exhaustivo O(2^N * m)
//Recibe una matriz binaria (1 y 0) y entrega un subconjunto de filas tal que en todas las columnas existan al menos un 1
//TODO programar la lectura/conversion de la entrada y quitar un poco de for-loop's

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include "tools1.h"
using namespace std;


vector<int> exhaustiveSearch(int m, int n, vector<bool> &matrix){
    vector<int> result(m);//msc mas pequeño encontrado hasta el momento
    vector<bool> aux(n); //elementos cubiertos en cada iteracion
    vector<bool> combi(m); //vector ayuda para recorrer las combinaciones posibles
    int c; //numero de sets añadidos en cada iteracion
    initCombi(combi);
    initVector(result, m);

    //testea todas las 2^m combinaciones distintas de sets
    for(int i = 0; i < pow(2,m) - 1; i++){
        c = 0;
        restartVector(aux, n);
        for(int j = 0; j <= n; j++){
            if(combi[j]){
                //Añade los elementos cubiertos por el conjunto al aux
                for(int l = 0; l < n; l++) aux[l] = aux[l] or matrix[(j * n) + l];
                c++;
            }
        }
        if(result.size() > c and setCover(aux, n)){
            result.clear();
            for(int k = 0; k < n; k++){
                if(combi[k]) result.push_back(k);
            }
        }
        plusOne(combi);
    }
    return result;
}

vector<int> optimizedES(int m, int n, vector<bool> &matrix){
    vector<int> result(m);
    vector<bool> aux(n); //elementos cubiertos en cada combinacion
    vector<bool> combi(m); //vector ayuda para recorrer las combinaciones posibles
    int c; //numero de sets añadidos en cada instante
    initCombi(combi);
    initVector(result, m);

    //testea todas las 2^m combinaciones distintas de sets
    for(int i = 0; i < pow(2,m) - 1; i++){
        c = 0;
        restartVector(aux, n);
        for(int j = 0; j <= n; j++){
            //optimizacion 2: si los conjuntos agregados son mayores a la solucion parcial paso de largo
            if(combi[j] and result.size() > c){ 
                //Añade los elementos cubiertos por el conjunto al aux
                for(int l = 0; l < n; l++) aux[l] = aux[l] or matrix[(j * n) + l];
                c++;
            }
        }
        if(result.size() > c and setCover(aux, n)){
            result.clear();
            for(int k = 0; k < n; k++){
                if(combi[k]) result.push_back(k);
            }
        }
        plusOne(combi);
    }
    return result;
}

vector<int> mscBusquedaOp(int n,int m,vector<bool> c){
    set<int> s;
    s = uniqueElem(m, n, c);
    int m1 = m - s.size(); //nuevo numero de conjuntos
    vector<int> sv={}; 
    for(int a: s) sv.push_back(a);

    //union de los sets con elemento unico
    vector<bool> aux1(n);
    restartVector(aux1, n);
    for(int b: sv){
        for(int l = 0; l < n; l++){
            aux1[l] = aux1[l] or c[(b * n) + l];
            } 
    }

    int n1 = 0; //Nuevo numero de elementos
    for (bool a: aux1) a ? n1 += 0 : n1 += 1; 

    //creo una nueva matriz que no contiene los conjuntos con elem unicos ni los elem. que cubren
    deleteRows(sv, c, n);
    deleteColumns(m, n, c, aux1);
    vector<int> msc;
    msc = optimizedES(m1, n1, c);
    return msc;
}