#include <iostream>
#include <string>
using namespace std;

class Boligrafo {
	private:
		int tinta;
		string color;
		
	public:
		Boligrafo();
		int getTinta();
		string getColor();
		bool setColor(string cambioColor);
		bool escribir(int usado);
		bool recargar(int aumento);
		void mostrarEstado();
};

Boligrafo::Boligrafo(){
	tinta = 100;
	color = "azul";
}

int Boligrafo::getTinta(){
	return tinta;
}

string Boligrafo::getColor(){
	return color;
}

bool Boligrafo::setColor(string cambioColor){
	if(cambioColor == "azul" || cambioColor == "rojo" || cambioColor == "verde" || cambioColor == "negro"){
		color = cambioColor;
		return true;
	} else {
		return false;
	}
}

bool Boligrafo::escribir(int usado){
	if(usado >= 0 && usado <= tinta){
			tinta = tinta - usado;
			return true;
	} else {
		return false;
	}
}

bool Boligrafo::recargar(int aumento){
	if(aumento > 0 && tinta + aumento <= 100){
			tinta = tinta + aumento;
			return true;
	} else {
		return false;
	}
}

void Boligrafo::mostrarEstado(){
	cout << "Cantidad de Tinta: " << tinta << "\n";
	cout << "Color del Boligrafo: " << color << "\n";
}

int main(){
	Boligrafo pilot;
	string cambioColor;
	int usado;
	int aumento;
	int opcion;
	
	do{
		cout << "-----Menu-----\n";
		cout << "1.Escribir.\n";
		cout << "2.Recargar.\n";
		cout << "3.Cambiar de color.\n";
		cout << "4.Consultar estado.\n";
		cout << "5.Salir del programa.\n";
		cout << "Elige una opcion\n";
		cin >> opcion;
		cout << "\n";
		
		switch(opcion){
			case 1:
				cout << "Ingrese la cantidad de tinta usada: ";
				cin >> usado;
				cout << endl;
				
				if(pilot.escribir(usado)){
					cout << "Tinta usada: " << usado << endl;
					cout << "Tinta restante: " << pilot.getTinta() << endl;
					cout << endl;
				} else {
					cout << "No se pudo usar el Boligrafo...\n";
					cout << endl;
				}
				break;
				
			case 2:
				cout << "Ingrese la cantidad de la recarga: ";
				cin >> aumento;
				cout << endl;
				
				if(pilot.recargar(aumento)){
					cout << "Cantidad aumentada: " << aumento << endl;
					cout << "Total de Tinta: " << pilot.getTinta() << endl;
					cout << endl;
				} else {
					cout << "No se pudo realizar la recarga...\n";
					cout << endl;
				}
				break;
			
			case 3:
				cout << "Ingrese el color al que desee cambiar (azul,rojo,verde,negro): ";
				cin >> cambioColor;
				
				if(pilot.setColor(cambioColor)){
					cout << "Se cambio el color correctamente...\n";
					cout << "Color actual: " << pilot.getColor() << endl;
				} else {
					cout << "No se pudo cambiar el color...\n";
					cout << endl;
				}
				break;
			
			case 4:
				cout << "Estado del Boligrafo...\n";
				cout << pilot.getColor() << endl;
				cout << pilot.getTinta() << endl;
				cout << endl;
				break;
				
			case 5:
				cout << "Cerrando el Programa...\n";
				cout << endl;
				break;
				
			default:
				cout << "Opcion no valida.Intentelo de nuevo\n";
				cout << endl;
				break;
 		}
	}while(opcion!=5);
	
	return 0;
}







