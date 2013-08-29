
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

vector <string> arr;

int heapSize;

//cambiar dos posiciones del arreglo
void Exchange(int a, int b){
  string tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

//Operaciones basicas del heap
//Nodo Padre del nodo i
int Parent(int i){
  return i/2;
}

//Nodo hijo izquierdo del nodo i
int Left(int i){
  return 2*i;
}

//Nodo hijo derecho del nodo i
int Rigth(int i){
  return 2*i + 1;
}

//Funcion para mantener propiedad de maximos en el heap
//Supone que los nodos Izq. y Der. del heap estan ordenados.
void MaintainHeap(int i){
  int l = Left(i);
  int r = Rigth(i);

  int largest;

  if(l < heapSize && arr[l].compare(arr[i]) > 0){
    largest = l;
  } else {
    largest = i;
  }

  if (r < heapSize && arr[r].compare(arr[largest]) > 0){
    largest = r;
  }

  if (largest != i){
    Exchange(i, largest);
    MaintainHeap(largest);
  }
}

//construir el heap en el arreglo global arr
void BuildHeap (){
  heapSize= arr.size();
  for (int i = arr.size()-1/2; i>=0; i--){
    MaintainHeap(i);
  }
}

//Correr heapsort en el arreglo global arr
void Heapsort(){
  for (int i=arr.size()-1; i>=1; i--){
    Exchange(0, i);
    heapSize = heapSize-1;
    MaintainHeap(0);
  }
}

int main (){
  string temp; //Temporal para guardar los valores leidos.
  while(cin>>temp){  //Lee valores "mientras pueda".
    arr.push_back(temp);
  }

  cout<<"sorting input..."<<endl<<endl;

  //inicio del timer
  clock_t timer;
  timer = clock();
  
  //construir heap en arr y ordenar
  BuildHeap();
  Heapsort();

  //imprimir arreglo ordenado
  cout<<"Output: "<<endl<<endl;
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<endl;
  }
    
  //imprimir cuanto tiempo tardo en ordenar el arrglo
  timer = clock() - timer;
  cout<<endl<<"Done in "<<((float) timer)/CLOCKS_PER_SEC<<" seconds"<<endl;

  //imprimir espacio real estimado usado por el algoritmo
  cout<<"Memory space used :"<<sizeof(string)*arr.size()<<" bytes."<<endl;

  return 0;
}
