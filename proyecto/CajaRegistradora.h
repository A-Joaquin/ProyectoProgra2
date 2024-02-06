#pragma once
#include "Transaccion.h"
class CajaRegistradora
{
private:
	bool abierto=1;
	vector<Transaccion*> transacciones;
	int id;

public:
	CajaRegistradora();
	CajaRegistradora(int id);
	~CajaRegistradora();
	int getId();
	void cerrarCaja();
	void abrirCaja();
	bool getEstado();
	void setId(int id);
	vector<Transaccion* > getTransacciones();
	void agregarTransaccion(Transaccion* transaccion);
};

