#pragma once
#include "Producto.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Alimento.h"
#include "ArticuloDelHogar.h"
#include "CuidadoPersonal.h"
#include "Carrito.h"	
#include "Fecha.h"
class Cliente;

class Transaccion
{
private:
	int id;
	float monto=0;
	Fecha fecha;
	Cliente* clienteTransaccion;
	Empleado* empleadoTransaccion;
	Carrito carrito;

	/*vector<Producto> productosTransaccion;*/
public:
	Transaccion();
	Transaccion(int id,Fecha fecha);
	void setFecha(Fecha fecha);
	void setCliente(Cliente* cliente);
	void setMonto(float monto);
	void setEmpleado(Empleado* empleado);
	int getId();
	float getMonto();
	Fecha getFecha();
	Cliente* getCliente();
	Empleado* getEmpleado();
	Carrito getCarrito();
	void mostrarTransacciones();
	void agregarCarrito(Carrito carrito);
	void setId(int id);
};

