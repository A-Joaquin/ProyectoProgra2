#include "Proveedor.h"

Proveedor::Proveedor()
{
}

Proveedor::Proveedor(int idProveedor, string nombreProveedor, string direccionProveedor, int telefonoProveedor)
{
	this->idProveedor = idProveedor;
	this->nombreProveedor = nombreProveedor;
	this->direccionProveedor = direccionProveedor;
	this->telefonoProveedor = telefonoProveedor;
}

void Proveedor::añadirProducto(Producto* producto)
{
	productosProveedor.push_back(producto);
}

int Proveedor::getId()
{
	return idProveedor;
}

string Proveedor::getNombre()
{
	return nombreProveedor;
}

string Proveedor::getDatosProveedor()
{
	return "id: "+to_string(idProveedor) + " nombre: " + nombreProveedor;
}

string Proveedor::getDireccion()
{
	return direccionProveedor;
}

int Proveedor::getTelefono()
{
	return telefonoProveedor;
}

vector<Producto*> Proveedor::getProductos()
{
	return productosProveedor;
}

void Proveedor::setIdProductos(vector<int> idProductos)
{
	this->idProductos = idProductos;
}

vector<int> Proveedor::getIdProductosLoadData()
{
	return idProductos;
}

void Proveedor::setId(int id)
{
	this->idProveedor = id;
}

void Proveedor::setNombre(string nombre)
{
	this->nombreProveedor = nombre;
}

void Proveedor::setDireccion(string direccion)
{
	this->direccionProveedor = direccion;
}

void Proveedor::setTelefono(int telefono)
{
	this->telefonoProveedor = telefono;
}


