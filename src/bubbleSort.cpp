
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

vector <string> arr;

//intercambiar los valores de dos posiciones del arreglo
void Exchange(int posA, int posB){
  string temp;
  temp=arr[posA];
  arr[posA]=arr[posB];
  arr[posB]=temp;
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
  
  for (int i=0; i<arr.size(); i++){
    for(int j=arr.size()-1; j>i; j--){
      if(arr[j].compare(arr[j-1]) < 0){
	//intercambiar arr[j] y arr[j-1]
	Exchange(j,j-1);
      }
    }
  }
  
  //imprimir arreglo ordenado
  cout<<"Output: "<<endl<<endl;
  for(int i=0; i<arr.size(); i++){
      cout<<arr[i]<<endl;
  }
    
  cout<<endl;

  //imprimir cuanto tiempo tardo en ordenar el arrglo
  timer = clock() - timer;
  cout<<"Done in "<<((float) timer)/CLOCKS_PER_SEC<<" seconds"<<endl;

  //imprimir espcaio real aproximado ocupado por el vector (en bytes)
  cout<<"Memory space used to sort : "<<sizeof(string)*arr.size()<<endl;

  return 0;
}
