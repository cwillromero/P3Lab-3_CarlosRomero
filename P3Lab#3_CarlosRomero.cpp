#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

char menu();
void ejercicio1();
void ejercicio2();
void ejercicio3();
string mezclar(string*);

int main(){
	char opcion='a';
	while(opcion!='4'){
		opcion=menu();
		switch(opcion){
			case '1': {
				cout<<endl<<"-----Ejericio 1------"<<endl;
				ejercicio1();
				cout<<endl;
			break;
			        }
			case '2': {
				cout<<endl<<"-----Ejericio 2------"<<endl;
				ejercicio2();
				cout<<endl;
			break;
			        }
			case '3': {
				cout<<endl<<"-----Ejericio 2------"<<endl;
				ejercicio3();
				cout<<endl;
			break;
				}
			case '4':{

			break;
				 }
		}
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
	int* numeros =NULL;
	numeros=new int [size];
	for(int i=0; i<size; i++){
		numeros[i]=rand()%9+1;
	}
	int contador=size;
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
	cout<<"Permutaciones: "<<endl;
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
	int cont1=0;
	int cont2=0;
	int cont3=0;
	int cont4=0;	
	for(int i=0; i<4;i++){
		if(arreglo[i]==arreglo[0])
			cont1++;
		if(arreglo[i]==arreglo[1])
			cont2++;
		if(arreglo[i]==arreglo[2])
			cont3++;
		if(arreglo[i]==arreglo[3])
			cont4++;
	}
	if(cont1==1 && cont2==1 && cont2==1 && cont4==1){
		for(int i=0; i<4; i++){
			posicion=rand()%4+0;
			if(repetido.find(arreglo[posicion] )==string::npos){
				numero[i]=arreglo[posicion];
				repetido=repetido+numero[i];
			}else{
				i=i-1;
			}
		}
	}
	else{
		for(int i=0; i<4; i++){
			posicion=rand()%4+0;
			numero[i]=arreglo[posicion];
		}
	}
	string mezcla;
	mezcla=""+numero[0]+numero[1]+numero[2]+numero[3];
	return mezcla;
}


void ejercicio3(){
	int Anio;
	int Mes;
	int Dia;
	string DiaSemana1;
	string bisiesto=".";
	string anio;
	string mes;
	string dia;
	while(true){
		string fecha;
		cout<<"Ingrese una fecha en formato [AAAAMMDD]: ";
		cin>>fecha;
		cout<<endl;
		if(fecha.size()!=8){
			cout<<"Fecha errónea"<<endl;
		}else{
			anio=fecha.substr(0,4);
			mes=fecha.substr(4,2);
			dia=fecha.substr(6,8);
			Anio=atoi(anio.c_str());
			Mes=atoi(mes.c_str());
			Dia=atoi(dia.c_str());
			if(Anio==2018 && (Dia>9 ||  Mes>2)){
				cout<<"Fecha errónea"<<endl;
			}else if(Anio>2018 || Dia>31 || Mes>12){
				cout<<"Fecha errónea"<<endl;
			}else if(Mes==2 && Dia>28){
				cout<<"Fecha errónea"<<endl;
			}else{
				if(Mes==1)
					mes="Enero";
				if(Mes==2)
					mes="Febrero";
				if(Mes==3)
					mes="Marzo"; 
				if(Mes==4)
					mes="Abril";	
				if(Mes==5)
					mes="Mayo";
				if(Mes==6)
					mes="Junio";
				if(Mes==7)
					mes="Julio";
				if(Mes==8)
					mes="Agosto";
				if(Mes==9)
					mes="Septiembre";
				if(Mes==10)
					mes="Octubre";
				if(Mes==11)
					mes="Noviembre";
				if(Mes==12)
					mes="Diciembre";
				if(Anio%4==0 && Anio%100==0 && Anio%400==0){
					bisiesto=" Es Año Bisiesto. ";
				}
				double diaSemana=((Anio-1)%7+((Anio-1)/4-3*((Anio-1)/100+1)/4)%7+Mes+(Dia%7))%7;
				if(diaSemana==6)
					DiaSemana1="Domingo";
				if(diaSemana==0)
					DiaSemana1="Lunes";
				if(diaSemana==1)
					DiaSemana1="Martes";	
				if(diaSemana==2)
					DiaSemana1="Miercoles";
				if(diaSemana==3)
					DiaSemana1="Jueves";
				if(diaSemana==4)
					DiaSemana1="Viernes";
				if(diaSemana==5)
					DiaSemana1="Sábado";
				break;
			}
		}

	}

	cout<<DiaSemana1<<", "<<Dia<<" de "<<mes<<" de "<<Anio<<bisiesto<<endl;

}
