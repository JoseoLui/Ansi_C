#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <stdlib.h> // srand, rand
#include <time.h>
// Definiciones
#define M 1000
#define N 10
using namespace std;

// Devuelve un numero aleatorio
int rand_int(){
    // seed
    int magic_int = rand() % 100 + 1;
    return magic_int;
}
// Llena un arreglo bidimensional con valores aleatorios
void rand_matrix(int data[M][N]){
    for (int i=0; i<M; i++)
        for (int j=0; j<N;j++)
            data[i][j]=rand_int();
}
// Muestra la matriz
void show_matrix(int data[M][N]){
    for (int i=0; i<M; i++){
        cout<<"|";
        for (int j=0; j<N;j++){
            cout<<data[i][j]<<"|";}
        cout<<"\n";
    }
}
// data structure
struct MyMatrix{
    /**** Data ****/
    int matrix[M][N]; // Datos independientes
    int total; // Recurso compartido
    MyMatrix(){rand_matrix(matrix);total=0;};
    /**** Sync *****/
    mutex suma; // permite sumar
    mutex pantalla;
    /*** Work func ***/
 };

void work(MyMatrix *matrix, int id){
    // el id sirve para ver quien utilizara la fila
    int subtotal = 0;
    for (int j=0;j<N;j++){
        subtotal+=matrix->matrix[id][j];
    }
    /*** shared resource ***/
    matrix->suma.lock();
    matrix->total+=subtotal;
    matrix->suma.unlock();
    /** subtotal ***/
    matrix->pantalla.lock();
    cout<<"Worker "<<id<<" id:"<<this_thread::get_id()<<"\n";
    cout<<"      subtotal:"<<subtotal<<"\n";
    cout<<"      total:"<<matrix->total<<"\n\n";
    matrix->pantalla.unlock();
    
}

int main(int argc, const char * argv[])
{
    // Inicia la matrix
    cout<<"* Matrix: \n";
    MyMatrix *matrix = new MyMatrix();
    show_matrix(matrix->matrix);
    cout<<"* End Matrix\n";
    // Creando threads (workers)
    vector<thread> workers;
    for (int i=0;i<M;i++){
        workers.push_back(thread( [=](){
            // from this thread
            work(matrix, i);
        } ));
    }
    
    for(auto& worker : workers){
        worker.join();
    }
    
    cout<<"resultado final:"<<matrix->total<<"\n";

    return 0;
}
