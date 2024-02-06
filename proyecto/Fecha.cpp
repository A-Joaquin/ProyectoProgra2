#include "Fecha.h"

using namespace std;

Fecha::Fecha() {
    time_t now = time(0);
    tm localTime;
    localtime_s(&localTime, &now);

     dia = localTime.tm_mday;
    mes = localTime.tm_mon + 1;
    anio = localTime.tm_year + 1900;
}

string Fecha::obtenerFechaActual() const {
    return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}

int Fecha::obtenerDia() const {
    return dia;
}

int Fecha::obtenerMes() const {
    return mes;
}

int Fecha::obtenerAnio() const {
    return anio;
}
void Fecha::convertirString(const string& fechaString) {

    size_t pos1 = fechaString.find('/');
    size_t pos2 = fechaString.find('/', pos1 + 1);

    string diaStr = fechaString.substr(0, pos1);
    string mesStr = fechaString.substr(pos1 + 1, pos2 - pos1 - 1);
    string anioStr = fechaString.substr(pos2 + 1);


    dia = stoi(diaStr);
    mes = stoi(mesStr);
    anio = stoi(anioStr);
}

