#include "Transaccion.h"

Transaccion::Transaccion()
{
}

Transaccion::Transaccion(int id, Fecha fecha)
{
	this->id = id;

	this->fecha = fecha;
}

void Transaccion::setFecha(Fecha fecha)
{
	this->fecha = fecha;
}



void Transaccion::setCliente(Cliente* cliente)
{
	this->clienteTransaccion = cliente;
}

void Transaccion::setMonto(float monto)
{
	this->monto = monto;
}

void Transaccion::setEmpleado(Empleado* empleado)
{
	this->empleadoTransaccion = empleado;
}

int Transaccion::getId()
{
	return id;
}

float Transaccion::getMonto()
{
	return monto;
}

Fecha Transaccion::getFecha()
{
	return fecha;
}

Cliente* Transaccion::getCliente()
{
	return clienteTransaccion;
}

Empleado* Transaccion::getEmpleado()
{
	return empleadoTransaccion;
}

Carrito Transaccion::getCarrito()
{
	return carrito;
}

void Transaccion::mostrarTransacciones()
{
	cout << "TRANSACCION" <<endl;
	cout << "id: " << id << endl;
	cout << "fecha: " << fecha.obtenerFechaActual()<<endl;
	for (int i = 0; i < carrito.getCarrito().size(); i++)
	{
		cout<< carrito.getCarrito()[i]->getDatosProducto()<<endl;
	}
}

void Transaccion::agregarCarrito(Carrito carrito)
{
	carrito.calcularTotal();
	this->carrito = carrito;
	this->monto = carrito.getTotal();
}

void Transaccion::setId(int id)
{
	this->id = id;
}

//void Transaccion::mostrarTransacciones()
//{
//	for (int i = 0; i < productosTransaccion.size(); i++)
//	{
//		cout<< productosTransaccion[i]->getDatosProducto()<<endl;
//	}
//}

//void Transaccion::agregarProducto(Producto* producto)
//{
//	productosTransaccion.push_back(producto);
//}
