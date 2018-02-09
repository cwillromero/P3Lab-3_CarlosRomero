#include <iostream>
#include <string>
using namespace std;

char menu();
void ejercicio1();
void ejercicio2();
void ejercicio3();
string mezclar(string*);

int main(){
	char opcion=menu();
	switch(opcion){
		case '1': {
			cout<<endl<<"-----Ejericio 1------"<<endl;
		break;
		        }
		case '2': {
			cout<<endl<<"-----Ejericio 2------"<<endl;
			ejercicio2();
		break;
		        }
		case '3': {
			cout<<endl<<"-----Ejericio 2------"<<endl;
		break;
			}
		case '4':
		break;
	}
	return 0;
}

//Menu
char menu(){
	char opcion=0;
	cout<<"------Menu - Lab 3------"<<endl
	<<"1- Ejercicio 1: Mediana de Medianas"<<endl
	<<"2- Ejercicio 2: Permutación"<<endl
	<<"3- Ejercicio 3: Fechas"<<endl
	<<"4- Salir"<<endl<<endl
	<<"Elija una opción: ";
	cin>>opcion;
	cout<<endl;
	while(opcion!='1' && opcion!='2' && opcion!='3' && opcion!='4'){
		cout<<"Incorrecto! Elija una opción: ";
		cin>>opcion;
		cout<<endl;
	}	
	return opcion;	
}

void ejercicio1(){
	cout<<"Ingrese el tamaño del arreglo: ";
	int size=0;
	cin>>size;
}

void ejercicio2(){
	string numero;
	cout<<"Ingrese un numero de cuatro digitos: ";
	cin>>numero;
	cout<<endl;
	while(numero.size()!=4){
		cout<<"ERROR! Ingrese un numero de cuatro digitos: ";
		cin>>numero;
		cout<<endl;
	}
	cout<<numero<<endl;
	string* numeros=NULL;
	string* permutaciones=NULL;
	numeros=new string[4];
	permutaciones=new string[12];
	numeros[0]=numero.substr(0,1);
	numeros[1]=numero.substr(1,1);
	numeros[2]=numero.substr(2,1);
	numeros[3]=numero.substr(3,3);
	for(int i=0; i<12; i++){
		permutaciones[i]=mezclar(numeros);
		cout<<"["<<permutaciones[i]<<"]"<<endl;
	}
	delete[] numeros;
	delete[] permutaciones;
	permutaciones=NULL;
	numeros=NULL;
}

string mezclar(string* arreglo){
	int posicion=0;
	string*numero=NULL;
	numero=new string[4];
	string repetido="";
	for(int i=0; i<4; i++){
		posicion=rand()%4+0;
		if(repetido.find(arreglo[posicion] )==string::npos){
			numero[i]=arreglo[posicion];
			repetido=repetido+numero[i];
		}else{
			i=i-1;
		}
	}
	string mezcla;
	mezcla=""+numero[0]+numero[1]+numero[2]+numero[3];
	return mezcla;
}

