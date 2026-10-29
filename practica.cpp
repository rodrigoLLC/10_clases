#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Pelicula {
	private:
		string titulo;
		int duracion;
		float precio;
		
	public:
		Pelicula();
		void setTitulo(string);
		void setDuracion(int);
		void setPrecio(float);
		string getTitulo();
		int getDuracion();
		float getPrecio();
		void mostrarInformacion(); 
};

Pelicula::Pelicula(){
	titulo = "(Sin Titulo)";
	duracion = 0;
	precio = 0.0;
}

void Pelicula::setTitulo(string nuevoTitulo){
	titulo = nuevoTitulo;
}
void Pelicula::setDuracion(int nuevaDuracion){
	duracion = nuevaDuracion;
}
void Pelicula::setPrecio(float nuevoPrecio){
	precio = nuevoPrecio;
}

string Pelicula::getTitulo(){
	return titulo;
}
int Pelicula::getDuracion(){
	return duracion;
}
float Pelicula::getPrecio(){
	return precio;
}

void Pelicula::mostrarInformacion(){
	cout << "DATOS DE LA PELICULA\n";
	cout << "Titulo: " << titulo << "\n";
	cout << "Duracion: " << duracion << "\n";
	cout << "Precio: S/" << std::fixed << setprecision(2) << precio << "\n"; 
}

int main(){
	Pelicula pelicula1;
	
	pelicula1.mostrarInformacion();
	
	pelicula1.setTitulo("Titanic");
	pelicula1.setDuracion(195);
	pelicula1.setPrecio(12.50);
	
	cout << "Despues del registro\n";
	pelicula1.mostrarInformacion();	
	
	cout << "Consultando mediante un getter:\n";
	cout << pelicula1.getTitulo() << "\n";
	
	return 0;
}



