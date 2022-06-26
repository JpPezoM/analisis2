//Min Set Cover(Unicost) Metodo Exhaustivo O(2^N)
//Recibe una matriz binaria y entrega un subconjunto de filas tal que cubren todas las columnas con al menos un 1
//En realidad no esta probando todas las combinaciones, tengo que arreglar eso.
//TODO dejar funciones en archivo .h aparte, programar la lectura/conversion de la entrada y quitar un poco de for-loop's

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

/*
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
*/
void printVector(vector<int> &lol){
    printf("(");
    for(int l: lol) printf("%i ", l);
    printf(")\n");
}

void printVector(vector<bool> &lol){
    printf("(");
    for(bool l: lol) l ? printf("1") : printf("0");
    printf(")\n");
}

void restartVector(vector<bool> &v, int n){
    for(int i = 0; i < n; i++){
        v[i] = false;
    }
}

void initVector(vector<int> &v, int n){
    for(int i = 0; i < n; i++){
        v[i] = i;
    }
}

bool setCover(vector<bool> &v, int n){
    bool b = true;
    for(int i = 0; i < n; i++){
        if(not v[i]) b =false;
    }
    return b;
}

void initCombi(vector<bool> &b){
    b[0] = true;
    for(int i= 1; i < b.size(); i++){
        b[i] = false;
    }
}

void plusOne(vector<bool> &b){
    int c = 0;
    while(b[c] and c < b.size()){
        b[c] = false;
        c += 1;
    }
    if(c <= b.size()) b[c] = true;
    
}

vector<int> exhaustiveSearch(int m, int n, vector<bool> &matrix){
    vector<int> result(m);//msc mas pequeño encontrado en el momento
    vector<bool> aux(n); //elementos añadidos en cada instante
    vector<bool> combi(m); //vector de ayuda para calcular las combinaciones
    int c = 1; 
    initCombi(combi);
    initVector(result, m);

    for(int i = 0; i < pow(2,m); i++){
        c = 1;
        restartVector(aux, n);
        for(int j = 0; j <= n; j++){
            if(combi[j]){
                //Añade la fila al aux
                for(int l = 0; l < n; l++){
                aux[l] = aux[l] or matrix[(j * n) + l];
                }
                c++;
            }
            if(setCover(aux, n) and result.size() > c){
                result.clear();
                for(int k = 0; k < n; k++){
                    if(combi[k]) result.push_back(k);
                }
            }

        }
        plusOne(combi);
    }
    //comprueba con todas las combinaciones que contienen el 1er elmento, el 2do y asi
    /*for(int i = 0; i < m; i++){
        restartVector(aux, n);
        for(int j = i; j < m; j++){

            //añade la fila al aux
            for(int l = 0; l < n; l++){
                aux[l] = aux[l] or matrix[(j * n) + l];
            }

            setCover(aux, n) ? printf("True") : printf("False");
            printVector(aux);
            
            if(setCover(aux, n) and (result.size() > (j - i))){
                result.clear();
                for(int h = i; h <= j; h++){  
                    result.push_back(h);
                }
            }
        }
    }*/
    return result;
}

int main(){
    vector<bool> carlos(6*12); // matriz de prueba
    carlos = 
    {
        1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 
        1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
        0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0,
        0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1
    };

    vector<int> msc;
    msc = exhaustiveSearch(6, 12, carlos);
    printf("el minimum set cover es de tamaño: %u\n", msc.size());
    printVector(msc);
    return 0;
}