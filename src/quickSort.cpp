
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

vector <string> arr;

void ChangeStr( int a, int b){ //cambia un par de strings en el arreglo dado
  string tmp = arr[a];
  arr[a] = arr[b];
  arr[b] = tmp;
}

int Partition(int firstPos, int lastPos){ //divide el arreglo en dos
  string pivot = arr[lastPos]; //punto que termina indicando donde se parte el arreglo
  int i = firstPos-1;
  for (int j = firstPos; j<lastPos; j++){
    if (arr[j].compare(pivot) <= 0){
      i++;
      ChangeStr(i, j);
    }
  }
  ChangeStr(i+1, lastPos);
  return i+1; //retorna el pivote donde se debe partir el arreglo
}

void QuickSort( int first, int last){
  if (first < last){
    int pivot = Partition(first, last); //Divide
    QuickSort( first, pivot-1); // & Conquer
    QuickSort( pivot+1, last);
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
  
  //ordenar el arreglo
  QuickSort(0, arr.size()-1);

  //imprimir arreglo ordenado
  cout<<"Output: "<<endl<<endl;
  for(int i=0; i<arr.size(); i++){
    cout<<arr[i]<<endl;
  }
    
  //imprimir cuanto tiempo tardo en ordenar el arrglo
  timer = clock() - timer;
  cout<<endl<<"Done in "<<(float)((float) timer)/CLOCKS_PER_SEC<<" seconds"<<endl;

  //imprimir cuanto espcaio estimado ocupo el vector
  long long memSpace=sizeof(string) * arr.size();
  cout<<"Memory space used to sort: "<<memSpace<<" bytes."<<endl;

  return 0;
}
