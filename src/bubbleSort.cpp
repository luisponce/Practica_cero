
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

vector <string> arr;

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
          temp = arr[j-1];
          arr[j-1] = arr[j];
          arr[j] = temp;
      }
    }
  }
  
  //imprimir arreglo ordenado
  cout<<"Output: "<<endl<<endl;
  for(int i=0; i<arr.size(); i++){
      cout<<arr[i]<<endl;
  }
    
  //imprimir cuanto tiempo tardo en ordenar el arrglo
  timer = clock() - timer;
  cout<<endl<<"Done in "<<((float) timer)/CLOCKS_PER_SEC<<" seconds"<<endl;

  return 0;
}
