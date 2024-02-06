#include "Cliente.h"

Cliente::Cliente():Persona()
{

}

Cliente::Cliente(int id, string nombre, int edad, string direccion, int telefono, string correoElectronico):Persona(id,nombre,edad,direccion,telefono,correoElectronico)
{
	
}

void Cliente::anadirQueja(string queja)
{
	quejas.push_back(queja);
}

void Cliente::setPuntos(int puntos2)
{
	this->puntos = puntos2;
}

int Cliente::getPuntos()
{
	return puntos;
}

vector<string> Cliente::getQuejas()
{
	return quejas;
}

void Cliente::añadirTransacccion(Transaccion* venta)
{
	ventas.push_back(venta);
}

vector<Transaccion*> Cliente::getTransaccion()
{
	return ventas;
}

vector<int> Cliente::getVentasId()
{
	return ventas1;
}

void Cliente::setIdvENTAS(vector<int> ventas)
{
	this->ventas1 = ventas;
}

Cliente::~Cliente()
{
}
