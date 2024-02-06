#pragma once
class Transaccion;
using namespace std;
class ICliente
{
public:
	virtual void anadirQueja(string queja) = 0;
	virtual void añadirTransacccion(Transaccion* venta) = 0;
	virtual vector<Transaccion*> getTransaccion() = 0;
	virtual void setPuntos(int puntos2) = 0;
	virtual int getPuntos() =0;
	virtual ~ICliente()
	{
	}
};

