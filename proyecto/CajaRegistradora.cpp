#include "CajaRegistradora.h"

CajaRegistradora::CajaRegistradora()
{
}

CajaRegistradora::CajaRegistradora( int id)
{

	this->id = id;
	this->abierto = 0;

}

CajaRegistradora::~CajaRegistradora()
{
	for (Transaccion* transaccion : transacciones)
	{
		delete transaccion;
	}
}

int CajaRegistradora::getId()
{
	return id;
}

void CajaRegistradora::cerrarCaja()
{
	this->abierto = 0;
}

void CajaRegistradora::abrirCaja()
{
	this->abierto = 1;
}

bool CajaRegistradora::getEstado()
{
	return abierto;
}

void CajaRegistradora::setId(int id)
{
	this->id = id;
}

vector<Transaccion*> CajaRegistradora::getTransacciones()
{
	return transacciones;
}

void CajaRegistradora::agregarTransaccion(Transaccion* transaccion)
{
	transacciones.push_back(transaccion);
}


