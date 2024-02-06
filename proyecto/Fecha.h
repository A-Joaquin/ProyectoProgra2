#pragma once

#include <ctime>
#include <string>

using namespace std;

class Fecha {
private:
    int dia;
    int mes;
    int anio;

public:
    Fecha(); // Constructor que obtiene la fecha actual
    string obtenerFechaActual() const;
    int obtenerDia() const;
    int obtenerMes() const;
    int obtenerAnio() const;
    void convertirString(const string& fechaString);
};
