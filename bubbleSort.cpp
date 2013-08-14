#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector <string> arrInitial;  //Creacion del arreglo.

int compare(string str1, string str2){  //Funcion para comparar dos strings.
  char a[str1.length()];
  for(int i=0; i<str1.length(); i++){
    a[i]=str1[i];
  }
  char b[str2.length()];
  for(int j=0;j<str1.length(); j++){
    b[j]=str2[j];
  }
  return strcmp(a,b);
}

int main (){
  string temp; //Temporal para guardar los valores leidos.
  while(cin>>temp){  //Lector de valores "mientras pueda".
    arrInitial.push_back(temp);
  }

  for (int i=0; i<arrInitial.size(); i++){  //Inicio del bubble sort.
    bool compared = false;  //Booleano para terminar la ejecucion cuando no se compare.
    for(int j=i+1; j>=arrInitial.size()-i; j++){
      if(compare(arrInitial[j-1],arrInitial[j])>0){
	temp = arrInitial[j-1];
	arrInitial[j-1]=arrInitial[j];
	arrInitial[j]=temp;
	compared = true;
      }
    }

    //if(!compared) break;  //Break para parar el codigo cuando no se compare.
  }

  cout<<"Arreglo Ordenado: "<<endl;  //Impresion del arreglo.
  for(int i=0;i<arrInitial.size(); i++){  //Ciclo para impresion del arreglo.
    cout<<arrInitial[i]<<endl;
  }
  return 0;
}
