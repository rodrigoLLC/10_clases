#include <iostream>
using namespace std;

class Calculadora {
	private:
		float primero;
		float segundo;
		bool comprobar();
		 
	public:
		Calculadora();
		void setNumeros(float a, float b);
		float getPrimero();
		float getSegundo();
		float sumar();
		float restar();
		float multiplicar();
		bool dividir(float& resultado);		
};

Calculadora::Calculadora(){
	primero = 0;
	segundo = 0;
}

void Calculadora::setNumeros(float a, float b){
	primero = a;
	segundo = b;
}

float Calculadora::getPrimero(){
	return primero;
}

float Calculadora::getSegundo(){
	return segundo;
}

float Calculadora::sumar(){
	return primero + segundo;
}

float Calculadora::restar(){
	return primero - segundo;
}

float Calculadora::multiplicar(){
	return primero*segundo;
}

bool Calculadora::comprobar(){
	if(segundo != 0){
		return true;
	} else {
		return false;
	}
}

bool Calculadora::dividir(float& resultado){
	if(comprobar()){
		resultado = primero/segundo;
		return true;
	} else {
		return false;
	}
}

int main(){
	Calculadora casio;
	float a;
	float b;
	float resultado = 0;
	int opcion;
	
	do{
		cout << "-----Menu-----\n";
		cout << "1.Establecer numeros.\n";
		cout << "2.Sumar.\n";
		cout << "3.Restar.\n";
		cout << "4.Multiplicar.\n";
		cout << "5.Dividir.\n";
		cout << "6.Numeros almacenados.\n";
		cout << "7.Salir del programa.\n";
		cout << endl;
		cout << "Elige una opcion (1-7)...\n";
		cin >> opcion;
		cout << endl;
		
		switch(opcion){
			case 1:
				cout << "Ingrese los numeros: \n";
				cin >> a >> b;
				casio.setNumeros(a, b);
				break;
			
			case 2:
				cout << "\n";
				cout << "La suma es: " << casio.sumar();
				cout << "\n";
				break;
				
			case 3:
				cout << "\n";
				cout << "La resta es: " << casio.restar();
				cout << "\n";
				break;
				
			case 4:
				cout << "\n";
				cout << "La multiplicacion es: " << casio.multiplicar();
				cout << "\n";
				break;
			
			case 5:
				cout << "\n";
				if(casio.dividir(resultado)){
					cout << "La division es: " << resultado;
				} else {
					cout << "La division no es valida..." << endl;
				}
				cout << "\n";
				break;
				
			case 6:
				cout << "\n";
				cout << "Los numero registrados son: \n";
				cout << casio.getPrimero() << endl;
				cout << casio.getSegundo();
				cout << "\n";
				break;
				
			case 7:
				cout << "\n";
				cout << "Cerrando el programa...\n";
				cout << "\n";
				break;
				
			default:
				cout << "\n";
				cout << "Opcion no valida.Intentelo de nuevo...\n";
				cout << "\n";
				break;
		}
	}while(opcion!=7);
	
	return 0;
}


