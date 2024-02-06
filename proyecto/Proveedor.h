#pragma once
#include "Producto.h"

#include <vector>
using namespace std;

class Producto;

class Proveedor
{
private:
	int idProveedor;
	string nombreProveedor;
	string direccionProveedor;
	int telefonoProveedor;
	vector<Producto*> productosProveedor;
	vector<int> idProductos;
public:
	Proveedor();
	Proveedor(int idProveedor, string nombreProveedor, string direccionProveedor, int telefonoProveedor);
	void añadirProducto(Producto* producto);
	int getId();
	string getNombre();
	string getDatosProveedor();
	string getDireccion();
	int getTelefono();
	vector<Producto*> getProductos();
	
	void setIdProductos(vector<int> idProductos);
	vector<int> getIdProductosLoadData();

	void setId(int id);
	void setNombre(string nombre);
	void setDireccion(string direccion);
	void setTelefono(int telefono);
	
};

