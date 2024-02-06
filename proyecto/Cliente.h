#pragma once
#include "Persona.h"
#include "Transaccion.h"
#include <vector>
#include "ICliente.h"
class Transaccion;

class Cliente:public Persona,public ICliente
{
private:
	int puntos=0;
	vector<Transaccion*> ventas;
	vector<string> quejas;
	vector<int> ventas1;
public:
	Cliente();
	Cliente(int id, string nombre, int edad, string direccion, int telefono, string correoElectronico);
	void anadirQueja(string queja) override;
	void setPuntos(int puntos2) override;
	int getPuntos() override;
	vector<string> getQuejas();
	void añadirTransacccion(Transaccion* venta) override;
	vector<Transaccion*> getTransaccion() override;
	vector<int> getVentasId();
	void setIdvENTAS(vector<int> ventas);
	~Cliente();

};