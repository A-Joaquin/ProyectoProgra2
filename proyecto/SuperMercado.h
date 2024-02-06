#pragma once
#include "Cliente.h"
#include "Empleado.h"
#include "Producto.h"
#include "Factura.h"
#include "CajaRegistradora.h"
#include "Proveedor.h"
#include "Carrito.h"
#include "Id.h"
#include "Descuento.h"
#include <algorithm>
#include "Fecha.h"
#include "SaveData.h"
#include "LoadData.h"
class SuperMercado
{
private:


	LoadData loadData1;
	vector<Empleado* > empleados;
	vector<Cliente*> clientes;
	vector<Proveedor* > proveedores;
	vector<Producto* > productos;
	vector<Factura*> facturas;
	vector<CajaRegistradora*> cajasRegistradoras;
	vector<Descuento*> descuentos;

	Id<Empleado> IdEmpleado;
	Id<Cliente> IdCliente;
	Id<Proveedor> IdProveedor;
	Id<Producto> IdProducto;
	Id<Factura> IdFactura;
	Id<CajaRegistradora> IdCajaRegistradora;
	Id<Descuento> IdDescuentos;
	Id<Transaccion> IdTransaccion;


public:

	SuperMercado();
	void menu();
	void ingresarDatosEmpleado( float& salario);
	void registrarPersona( string& nombre, int& edad, string& direccion, int& telefono, string& correoElectronico);
	void registrarCliente();
	void registrarEmpleado();
	void añadirCajaRegistradora();
	void realizarUnaTrasaccion();
	void mostrarTrasaccionesDeUnCliente();
	//agregar Producto por Proveedor y añadie a la lista de productos
	Carrito agregarProductosAtrasaccion();
	

	int buscarProducto(int nroCodigo);
	void mostrarFacturas();
	void quitarProductoDeCarrito(Carrito& carrito, vector<int>& cantidadesParaLlevar);
	void quitarCantidadProductoDeCarrito(Carrito& carrito, vector<int>& cantidadesParaLlevar);
	void cambiarEstadoDeCajaRegistradora();
	void registrarProveedor();
	void registrarProducto();
	void actualizarCantidadProducto();
	void despedirEmpleado();
	void cambiarEstadoDeEmpleado();
	void EstablecerCargoDeEmpleado();


	void calcularGanancias();

	void gestionarInventario();


	void mostrarProductosMasVendidos();
	void mostrarProductosMenosVendidos();
	void mostrarProductosVendidosConCantidad();
	void productosSinVender();

	void agregarDescuentoAproducto();


	void abrirCaja();
	~SuperMercado();


	void loadData();
	void loadDataTXT();
	void saveData();


	//importante
	
	// abrir y cerrar cajas.
	//AGREGAR DESCUENTOS DEL PRODUCTO
	// 
	// Bien
	//cout << "1. ingresar Empleado" << endl; //Gerente tiene acceso
	//cout << "2. ingresar Cliente" << endl; //Operaciones o Atencion o Gerente tiene acceso
	//cout << "3. ingresar caja registradora" << endl; //gerente o Operaciones tiene acceso
	//cout << "4. realizar transaccion" << endl; //atencion o gerente tiene acceso
	//cout << "5. mostrar transacciones de un cliente" << endl; //falta agregar mas comentarios de precio cout<< //Finanzas o atencion o Operaciones tiene acceso
	//cout << "6. mostrar facturas" << endl;//falta agregar mas informacion para mostrar //Finanzas o atencion tiene acceso
	// 
	//cout <<registrar Producto //operaciones tiene acceso
	// --Elegir un proveedor para registrar el producto
	// cout<<registrar Proveedor<<<endl; //operaciones tiene acceso
	// 
				//mostrar puntos de cliente / tarjeta de fidelidad
	
	//cout <<despedir empleado //el gerente o Operaciones tiene acceso
	//cout <<cambiar estado de empleado //gerente o Operaciones tiene acceso

	//cout <<establecer cargos de empleados //gerente o Operaciones tiene acceso
	// 
	// 
	// //HACER
	//cout <<calcular impuestos //finanzas tiene acceso
	//cout <<calcular ganancias //finanzas tienen acceso

	//cout <<gestionar inventario / ingresar proveedor / ingrear producto
	//--mostrar proveedor y actualizar productos. //Operaciones o Gerente
	// 
	//datos estadisticos(productos mas vendidos) / productos deficientes //finanzas y operaciones tiene acceso
	//cout<<"Productos menos vendidos"<<endl;
	//cout<<"Productos mas vendidos"<<endl;

	//cout<<"Productos que no se vendieron"<<endl;
};

