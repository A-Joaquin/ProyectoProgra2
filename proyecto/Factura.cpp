#include "Factura.h"

Factura::Factura()
{
}

Factura::Factura(int id, int nit, string nombre)
{
	this->id = id;
	this->nit = nit;
	this->nombre = nombre;
}

int Factura::getId()
{
	return id;
}

int Factura::getNit()
{
	return nit;
}

string Factura::getNombre()
{
	return nombre;
}

Transaccion* Factura::getTransaccion()
{
	return transaccion;
}

string Factura::getDatos()
{
	return "id: " + to_string(transaccion->getId()) + "fecha: " + transaccion->getFecha().obtenerFechaActual() + "- id de la factura: " + to_string(id) + " Nit de la factura: " + to_string(nit) + " nombre de la factura: " + nombre;
}

void Factura::setTransaccion(Transaccion* transaccion)
{
	this->transaccion = transaccion;
}

void Factura::setId(int id)
{
	this->id = id;
}

void Factura::setNombre(string nombre)
{
	this->nombre = nombre;
}

void Factura::setNit(int nit)
{
	this->nit = nit;
}



