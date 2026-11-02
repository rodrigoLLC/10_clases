
#include <iostream>
using namespace std;

class Reloj {
    private:
        int horas, minutos, segundos;
        int bateria;

    public:
        Reloj(int h, int m, int s, int b);

        bool ajustarHora(int h, int m, int s);

        int getHoras();
        int getMinutos();
        int getSegundos();
        int getBateria();

        void tic_tac();
        void avanza(int h, int m, int s);
        void atrasa(int h, int m, int s);

        bool estaParado();
        void recargaBateria(int b);

        void horaFormato12();
        void horaFormato24();
};

Reloj::Reloj(int h, int m, int s, int b){
    if(h >= 0 && h <= 23 && m >= 0 && m <= 59 &&
       s >= 0 && s <= 59 && b >= 0 && b <= 100){
        horas = h;
        minutos = m;
        segundos = s;
        bateria = b;
    } else {
        horas = 0;
        minutos = 0;
        segundos = 0;
        bateria = 0;
    }
}

bool Reloj::ajustarHora(int h, int m, int s){
    if(h >= 0 && h <= 23 && m >= 0 && m <= 59 &&
       s >= 0 && s <= 59){
        horas = h;
        minutos = m;
        segundos = s;
        return true;
    } else {
        return false;
    }
}

int Reloj::getHoras(){
    return horas;
}

int Reloj::getMinutos(){
    return minutos;
}

int Reloj::getSegundos(){
    return segundos;
}

int Reloj::getBateria(){
    return bateria;
}

void Reloj::tic_tac(){
    if(bateria > 0){
        segundos++;
        bateria--;

        if(segundos == 60){
            segundos = 0;
            minutos++;
        }

        if(minutos == 60){
            minutos = 0;
            horas++;
        }

        if(horas == 24){
            horas = 0;
        }
    }
}

void Reloj::avanza(int h, int m, int s){
    if(h >= 0 && m >= 0 && s >= 0){
        long long total;

        total = horas * 3600LL + minutos * 60LL + segundos;
        total = total + h * 3600LL + m * 60LL + s;
        total = total % 86400;

        horas = total / 3600;
        minutos = (total % 3600) / 60;
        segundos = total % 60;
    }
}

void Reloj::atrasa(int h, int m, int s){
    if(h >= 0 && m >= 0 && s >= 0){
        long long total;

        total = horas * 3600LL + minutos * 60LL + segundos;
        total = total - h * 3600LL - m * 60LL - s;

        while(total < 0){
            total = total + 86400;
        }

        total = total % 86400;

        horas = total / 3600;
        minutos = (total % 3600) / 60;
        segundos = total % 60;
    }
}

bool Reloj::estaParado(){
    if(bateria == 0){
        return true;
    } else {
        return false;
    }
}

void Reloj::recargaBateria(int b){
    if(b > 0 && b <= 100 - bateria){
        bateria = bateria + b;
    }
}

void Reloj::horaFormato12(){
    int hora12;

    hora12 = horas;

    if(hora12 == 0){
        hora12 = 12;
    } else if(hora12 > 12){
        hora12 = hora12 - 12;
    }

    if(hora12 < 10){
        cout << "0";
    }

    cout << hora12 << ":";

    if(minutos < 10){
        cout << "0";
    }

    cout << minutos << ":";

    if(segundos < 10){
        cout << "0";
    }

    cout << segundos;

    if(horas < 12){
        cout << " AM";
    } else {
        cout << " PM";
    }

    cout << endl;
}

void Reloj::horaFormato24(){
    if(horas < 10){
        cout << "0";
    }

    cout << horas << ":";

    if(minutos < 10){
        cout << "0";
    }

    cout << minutos << ":";

    if(segundos < 10){
        cout << "0";
    }

    cout << segundos << endl;
}

int main(){
    Reloj reloj(12, 30, 0, 100);

    int opcion;
    int h, m, s;
    int aumento;
    int bateriaAntes;

    do{
        cout << "----- RELOJ DIGITAL -----\n";
        cout << "1. Consultar hora en formato 12 horas.\n";
        cout << "2. Consultar hora en formato 24 horas.\n";
        cout << "3. Ajustar hora.\n";
        cout << "4. Avanzar un segundo.\n";
        cout << "5. Avanzar manualmente la hora.\n";
        cout << "6. Atrasar manualmente la hora.\n";
        cout << "7. Recargar bateria.\n";
        cout << "8. Consultar bateria.\n";
        cout << "9. Salir del programa.\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        cout << endl;

        switch(opcion){
            case 1:
                cout << "Hora en formato 12 horas: ";
                reloj.horaFormato12();
                break;

            case 2:
                cout << "Hora en formato 24 horas: ";
                reloj.horaFormato24();
                break;

            case 3:
                cout << "Ingrese las horas: ";
                cin >> h;
                cout << "Ingrese los minutos: ";
                cin >> m;
                cout << "Ingrese los segundos: ";
                cin >> s;

                if(reloj.ajustarHora(h, m, s)){
                    cout << "Hora ajustada correctamente.\n";
                    reloj.horaFormato24();
                } else {
                    cout << "La hora ingresada no es valida.\n";
                }
                break;

            case 4:
                if(reloj.estaParado()){
                    cout << "El reloj esta detenido. Bateria agotada.\n";
                } else {
                    reloj.tic_tac();
                    cout << "El reloj avanzo un segundo.\n";
                    cout << "Hora actual: ";
                    reloj.horaFormato24();
                    cout << "Bateria restante: " << reloj.getBateria() << endl;
                }
                break;

            case 5:
                cout << "Ingrese las horas a avanzar: ";
                cin >> h;
                cout << "Ingrese los minutos a avanzar: ";
                cin >> m;
                cout << "Ingrese los segundos a avanzar: ";
                cin >> s;

                if(h >= 0 && m >= 0 && s >= 0){
                    reloj.avanza(h, m, s);
                    cout << "Hora actualizada: ";
                    reloj.horaFormato24();
                } else {
                    cout << "No se permiten cantidades negativas.\n";
                }
                break;

            case 6:
                cout << "Ingrese las horas a atrasar: ";
                cin >> h;
                cout << "Ingrese los minutos a atrasar: ";
                cin >> m;
                cout << "Ingrese los segundos a atrasar: ";
                cin >> s;

                if(h >= 0 && m >= 0 && s >= 0){
                    reloj.atrasa(h, m, s);
                    cout << "Hora actualizada: ";
                    reloj.horaFormato24();
                } else {
                    cout << "No se permiten cantidades negativas.\n";
                }
                break;

            case 7:
                cout << "Ingrese la cantidad de bateria a recargar: ";
                cin >> aumento;

                bateriaAntes = reloj.getBateria();
                reloj.recargaBateria(aumento);

                if(reloj.getBateria() > bateriaAntes){
                    cout << "Bateria recargada correctamente.\n";
                    cout << "Bateria actual: " << reloj.getBateria() << endl;
                } else {
                    cout << "No se pudo realizar la recarga.\n";
                }
                break;

            case 8:
                cout << "Nivel de bateria: " << reloj.getBateria() << endl;

                if(reloj.estaParado()){
                    cout << "Estado: Reloj detenido.\n";
                } else {
                    cout << "Estado: Reloj funcionando.\n";
                }
                break;

            case 9:
                cout << "Cerrando el programa...\n";
                break;

            default:
                cout << "Opcion no valida. Intentelo de nuevo.\n";
                break;
        }

        cout << endl;

    }while(opcion != 9);

    return 0;
}

