#pragma once
#include "Transaccion.h"
class Factura
{
private:
	int id;
	Transaccion* transaccion;
	int nit;
	string nombre;
public:
	Factura();
	Factura(int id,int nit,string nombre);
	int getId();
	int getNit();
	string getNombre();
	Transaccion* getTransaccion();
	string getDatos();
	void setTransaccion(Transaccion* transaccion);
	void setId(int id);
	void setNombre(string nombre);
	void setNit(int nit);
	

};

