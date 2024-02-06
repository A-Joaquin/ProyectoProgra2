#include <fstream>
#include "Producto.h"
#include "Alimento.h"
#include "ArticuloDelHogar.h"
#include "CuidadoPersonal.h"
#include <iostream>
#include "Cliente.h"
#include "Empleado.h"
#include "CajaRegistradora.h"
#include "Factura.h"
#include "Fecha.h"
#include "Carrito.h"
//#include <string>
using namespace std;
class LoadData
{
private:
    vector<Producto*> productos;
    vector<Cliente*> clientes;
    vector<Empleado*> empleados;
    vector<Proveedor*> proveedores;
    vector<CajaRegistradora*> cajas;
    vector<Factura*> facturas;
    vector<Transaccion*> trasacciones1;
    vector<Transaccion*> trasacciones2;

public:
    LoadData();
    void recuperarDatos(string archivoProductos, string archivoClientes, string archivoEmpleado, string archivoProveedores, string archivoCajas, string archivoFacturas, string archivoTransacciones, string archivoTransacciones2);
	vector<Producto*> cargarDatos(string archivo2);
    vector<Cliente*> recuperarClientes( string archivo);
    vector<Empleado*> recuperarEmpleados(string archivo);

    vector<Proveedor*> recuperarProveedores(string archivo);
    vector<CajaRegistradora*> recuperarCajas(string archivo);
    vector<Factura*> recuperarFacturas(string archivo);
    vector<Transaccion*> recuperarTransacciones(string archivoGuarda);

    int buscarTransaccion1(int idTransaccion);
    int buscarTransaccion2(int idTransaccion);

    int buscarCliente(int idCliente);
    int buscarEmpleado(int idEmpleado);
    int buscarProducto(int idProducto);
    int buscarProveedor(int proveedor);

    void ComplementarProducto_Proveedor();
    void ComplementarCliente_transaccion();
    vector<Producto*> getProductos();
    vector<Cliente*> getClientes();
    vector<Empleado*> getEmpleados();
    vector<Proveedor*> getProveedor();
    vector<CajaRegistradora*> getCajas();
    vector<Factura*> getFacturas();
};