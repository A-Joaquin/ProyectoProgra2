

#include "SuperMercado.h"

SuperMercado::SuperMercado()
{

}
void SuperMercado::menu()
{
	int opcion = -1;
	cout << "Sistema de supermercado" << endl;
	while (opcion != 0)
	{
		cout << "1. ingresar Empleado" << endl; 
		cout << "2. ingresar Cliente" << endl; 
		cout << "3. ingresar caja registradora" << endl;
		cout << "4. realizar transaccion" << endl;
		cout << "5. mostrar transacciones de un cliente" << endl;
		cout << "6. mostrar facturas" << endl;
		cout << "7. Gestionar Inventario" << endl;
		cout << "8. Despedir Empleado" << endl;
		cout << "9. Cambiar Estado Empleado" << endl;
		cout << "10. Cambiar Cargo Empleado" << endl;
		cout << "11. Calcular Ganancias" << endl;
		cout << "12. Agregar Descuento a un producto" << endl;
		cout << "13. Mostrar Productos Mas Vendidos" << endl;
		cout << "14. Mostrar Productos Menos Vendidos" << endl;
		cout << "15. Mostrar Productos Sin Vender" << endl;
		cout << "16 Abrir Caja" << endl;
		cout << "30. Guardar Datos" << endl;

		cin >> opcion;
		switch (opcion)
		{
		case 1:
			registrarEmpleado();
			break;
		case 2:
			registrarCliente();
			break;
		case 3:
			añadirCajaRegistradora();
			break;
		case 4:
			realizarUnaTrasaccion();
			break;
		case 5:
			mostrarTrasaccionesDeUnCliente();
			break;
		case 6:
			mostrarFacturas();
			break;
		case 7:
			gestionarInventario();
			break;
		case 8:
			despedirEmpleado();
			break;
		case 9:
			cambiarEstadoDeEmpleado();
			break;
		case 10:
			EstablecerCargoDeEmpleado();
			break;
		case 11:
			calcularGanancias();
			break;
		case 12:
			agregarDescuentoAproducto();
			break;
		case 13:
			mostrarProductosMasVendidos();
			break;
		case 14:
			mostrarProductosMenosVendidos();
			break;
		case 15:
			productosSinVender();
			break;
		case 16:
			abrirCaja();
			break;
			
		case 30:
			saveData();
			break;

		default:
			cout << "SELECCIONA UNA OPCION VALIDA" << endl;
			break;
		}
	}
}
void SuperMercado::ingresarDatosEmpleado(float &salario)
{
	cout << "ingrese salario" << endl;
	cin >> salario;
}

void SuperMercado::registrarPersona(string &nombre,int &edad,string &direccion,int &telefono,string &correoElectronico)
{
	cout << "ingrese un nombre" << endl;
	cin >> nombre;
	cout << "ingrese la edad" << endl;
	cin >> edad;
	cout << "ingrese la direccion" << endl;
	cin >> direccion;
	cout << "ingrese el telefono" << endl;
	cin >> telefono;
	cout << "ingrese un correo Electronico" << endl;
	cin >> correoElectronico;
}

void SuperMercado::registrarCliente()
{
	int id; 
	string nombre;
	int edad;
	string direccion;
	int telefono; 
	string correoElectronico;
	id = IdCliente.getId();
	registrarPersona(nombre,edad,direccion,telefono,correoElectronico);

	Cliente* cliente = new Cliente(id,nombre,edad,direccion,telefono,correoElectronico);
	clientes.push_back(cliente);

}

void SuperMercado::registrarEmpleado()
{
	int id;
	string nombre;
	int edad;
	string direccion;
	int telefono;
	string correoElectronico;
	float salario;
	id = IdEmpleado.getId();
	registrarPersona( nombre, edad, direccion, telefono, correoElectronico);
	ingresarDatosEmpleado(salario);
	Empleado* empleado=new Empleado(id,nombre,edad,direccion,telefono,correoElectronico,salario);
	empleado->asignarCargo();
	empleado->asignarHorario();
	empleados.push_back(empleado);
}

void SuperMercado::añadirCajaRegistradora()
{
	int id;
	id = IdCajaRegistradora.getId();
	cout << "Caja registradora añadida" << endl;

	CajaRegistradora* cajaRegistradora = new CajaRegistradora(id);
	cajasRegistradoras.push_back(cajaRegistradora);
}

void SuperMercado::realizarUnaTrasaccion()
{
	int posCaja,posCliente,posEmpleado;
	cout << "seleccione la caja" << endl;
	for (int i = 0; i < cajasRegistradoras.size(); i++)
	{
		cout << "[" << i << "] "<<"caja numero  Nro codigo:" <<cajasRegistradoras[i]->getId() << endl;
	}
	cin >> posCaja;
	if (cajasRegistradoras[posCaja]->getEstado() == 0)
	{
		cout << "La caja esta cerrada" << endl;
	}
	else
	{
		cout << "seleccione el cliente" << endl;
		for (int i = 0; i < clientes.size(); i++)
		{
			cout << "[" << i << "] " << "cliente numero    Nombre Cliente: " <<  clientes[i]->getNombre() << endl;
		}
		cin >> posCliente;
		cout << "seleccione el empleado" << endl;
		for (int i = 0; i < empleados.size(); i++)
		{
			cout << "[" << i << "] " << "empleado numero   Nombre Empleado: " << empleados[i]->getNombre() << endl;
		}
		cin >> posEmpleado;

		int id;
		id = IdTransaccion.getId();

		Fecha fecha;

		Carrito carrito1 = agregarProductosAtrasaccion();

		if (carrito1.getCancelarCompra() != 1)
		{
			Transaccion* transaccion = new Transaccion(id, fecha);


			carrito1.agregarDescuentos(descuentos);

			transaccion->agregarCarrito(carrito1);

			transaccion->setCliente(clientes[posCliente]);

			transaccion->setEmpleado(empleados[posEmpleado]);

			cajasRegistradoras[posCaja]->agregarTransaccion(transaccion);
			clientes[posCliente]->añadirTransacccion(transaccion);

			int idFactura, nitFactura;
			string nombreFactura;

			idFactura = IdFactura.getId();

			cout << "ingrese el nit de la factura" << endl;
			cin >> nitFactura;

			cout << "ingrese el nombre de la factura" << endl;
			cin >> nombreFactura;
			Factura* factura = new Factura(idFactura, nitFactura, nombreFactura);
			factura->setTransaccion(transaccion);
			facturas.push_back(factura);
		}
		else
		{
			IdTransaccion.disminuirId();
		}
	}
}

Carrito SuperMercado::agregarProductosAtrasaccion()
{
	Carrito carrito;
	int cantidadParaLlevar, opcion=0;
	vector<int> cantidadesParaLlevar;
	int nroCodigo = 999, posProducto;

	while (nroCodigo != 0)
	{
		cout << "Agregar Productos" << endl;
		cout << "INGRESE '0' PARA SALIR" << endl;
		cout << "ingrese el codigo del Producto" << endl;
		for (int i = 0; i < productos.size(); i++)
		{
			cout <<"codigo: " <<productos[i]->getId() << " nombre: " << productos[i]->getDetalle() << endl;
		}
		cin >> nroCodigo;
		posProducto = buscarProducto(nroCodigo);
		if (posProducto != -1)
		{
			cout << productos[posProducto]->getDatosProducto() << endl;
			cout << "agrega la cantidad que desea llevar" << endl;
			cin >> cantidadParaLlevar;
			productos[posProducto]->aumentarCantidadVendida(cantidadParaLlevar);
			productos[posProducto]->disminuirCantidad(cantidadParaLlevar);
			cantidadesParaLlevar.push_back(cantidadParaLlevar);

			carrito.agregarProducto(productos[posProducto]);
		}
	}
	cout << "escoja una opcion para continuar" << endl;
	cout << " 0. confirmar compra" << endl;
	cout << " 1. quitar un producto" << endl;
	cout << " 2. quitar cantidad de un producto" << endl;
	cout << " 3. cancelar la compra completa" << endl;
	cin >> opcion;


	if (opcion != 0)
	{
		if (opcion == 1)
		{
			quitarProductoDeCarrito(carrito, cantidadesParaLlevar);
		}
		if(opcion==2)
		{
			quitarCantidadProductoDeCarrito(carrito, cantidadesParaLlevar);
		}
		if (opcion == 3)
		{
			carrito.cancelarCompraDeCarrito();
		}
	}
	carrito.setCantidadesParaLlevar(cantidadesParaLlevar);
	return carrito;
}


void SuperMercado::mostrarTrasaccionesDeUnCliente()
{
	int posCliente;
	cout << "eliga un cliente" << endl;
	for (int i = 0; i < clientes.size(); i++)
	{
		cout << "[" << i << "] " << clientes[i]->getId() << " - " << clientes[i]->getNombre() << endl;
	}
	cin >> posCliente;
	for (int i = 0; i < clientes[posCliente]->getTransaccion().size();i++)
	{
		cout << "id: " << clientes[posCliente]->getTransaccion()[i]->getId() << endl;
		cout<<"fecha: "<<clientes[posCliente]->getTransaccion()[i]->getFecha().obtenerFechaActual() << endl;
		cout << "monto: " << clientes[posCliente]->getTransaccion()[i]->getMonto() << endl;
		clientes[posCliente]->getTransaccion()[i]->mostrarTransacciones();
	}
}



int SuperMercado::buscarProducto(int nroCodigo)
{
	int PosProducto=-1;
	for (int j = 0 ; j < productos.size(); j++)
	{
		if (nroCodigo == productos[j]->getId())
		{
			PosProducto = j;
			break;
		}
		else
		{
			PosProducto = -1;
		}
	}
	return PosProducto;
}

void SuperMercado::mostrarFacturas()
{
	for (int i = 0; i < facturas.size(); i++)
	{
		cout << facturas[i]->getDatos() << endl;
	}
}

void SuperMercado::quitarProductoDeCarrito(Carrito& carrito, vector<int>& cantidadesParaLlevar)
{
	int posicion,pos2;
	cout << "seleccione la posicion del producto" << endl;
	for (int i = 0; i < carrito.getCarrito().size(); i++)
	{
		cout << "["<<i<<"]  posicion "<<carrito.getCarrito()[i]->getDatosProducto() << endl;
	}
	cin >> posicion;
	if (posicion >= 0 && posicion < carrito.getCarrito().size()) {
		carrito.getCarrito().erase(carrito.getCarrito().begin() + posicion);
		cout << "Elemento eliminado." << endl;
	}
	else {
		cout << "Posición inválida." << endl;
	}
	cout << "vector de ventaaas" << endl;
	for (int i = 0; i < cantidadesParaLlevar.size(); i++)
	{
		cout<<"["<<i<<"] "<<cantidadesParaLlevar[i] << endl;
	}
	cin >> pos2;
	if (posicion >= 0 && posicion < cantidadesParaLlevar.size()) {
		auto it = next(cantidadesParaLlevar.begin(), posicion); // Obtener iterador en la posición deseada
		cantidadesParaLlevar.erase(it); // Eliminar el elemento en la posición especificada
		cout << "Elemento eliminado." << endl;
	}
	else {
		cout << "Posición inválida." << endl;
	}
}

void SuperMercado::quitarCantidadProductoDeCarrito(Carrito& carrito, vector<int>& cantidadesParaLlevar)
{
	int posicion, cantidadParaQuitar;
	cout << "seleccione la posicion del producto" << endl;
	for (int i = 0; i < carrito.getCarrito().size(); i++)
	{
		cout << "posicion [" << i << "] " << "cantidad del carrito: "<<cantidadesParaLlevar[i] << " "<< carrito.getCarrito()[i]->getDatosProducto() << endl;
	}
	cin >> posicion;
	cout << "ingrese la cantidad que desea quitar" << endl;
	cin >> cantidadParaQuitar;
	if (posicion >= 0 && posicion < cantidadesParaLlevar.size()) {
		cantidadesParaLlevar[posicion] = cantidadesParaLlevar[posicion] - cantidadParaQuitar;
		cout << "Cantidad Quitada eliminado." << endl;
	}
	else {
		cout << "Posición inválida." << endl;
	}
}

void SuperMercado::cambiarEstadoDeCajaRegistradora()
{
	int posCaja;
	cout << "Seleccione una caja registradora para cambiar su estado" << endl;
	for (int i = 0; i < cajasRegistradoras.size(); i++)
	{
		cout << "[" << i << "] id:" << cajasRegistradoras[i]->getId()<<" estado: ";
		if (cajasRegistradoras[i]->getEstado() == 1)
		{
			cout << "Abierto" << endl;
		}
		else
		{
			cout << "Cerrado" << endl;
		}
	}
	cin >> posCaja;
	if (cajasRegistradoras[posCaja]->getEstado() == 1)
	{
		cajasRegistradoras[posCaja]->cerrarCaja();
	}
	else
	{
		cajasRegistradoras[posCaja]->abrirCaja();
	}


}

void SuperMercado::registrarProveedor()
{
	int id=0,telefono;
	string nombre, direccion;
	id = IdProveedor.getId();
	cout << "Ingrese el Nombre del proveedor" << endl;
	cin >> nombre;
	cout << "ingrese la direccion del proveedor" << endl;
	cin >> direccion;
	cout << "Ingrese el telefono del Proveedor" << endl;
	cin >> telefono;

	Proveedor* proveedor = new Proveedor(id,nombre,direccion,telefono);
	proveedores.push_back(proveedor);
}

void SuperMercado::registrarProducto()
{
	int posProveedor;
	cout << "Eliga un proveedor" << endl;
	for (int i = 0; i < proveedores.size(); i++)
	{
		cout << proveedores[i]->getDatosProveedor() << endl;
	}
	cin >> posProveedor;
	int id = 0, cantidad;
	string nombre, detalle;
	float precio, precioCompra;
	string fechaDeCaducidad, marca, tipoDeAlimento, tipoDeArticulo, materialDeFabricacion, tipoDeProducto, recomendacionesDeUso;

	int tipoDeProductoAregistrar;
	id = IdProducto.getId();
	cout << "Eliga que tipo de producto esta registrando" << endl;
	cout << "1. Alimento" << endl;
	cout << "2. Articulo del hogar" << endl;
	cout << "3. Cuidado Personal" << endl;
	cin >> tipoDeProductoAregistrar;
	cout << "ingrese el nombre del producto" << endl;
	cin >> nombre;
	cout << "ingrese el detalle del producto" << endl;
	cin >> detalle;
	cout << "Ingrese el precio del producto" << endl;
	cin >> precio;
	cout << "Ingrese el precio de Compra" << endl;
	cin >> precioCompra;
	cout << "Ingrese la marca del producto" << endl;
	cin >> marca;
	cout << "Ingrese la cantidad del producto" << endl;
	cin >> cantidad;
	Alimento* alimento;
	ArticuloDelHogar* articuloDelHogar;
	CuidadoPersonal* cuidadoPersonal;

	switch (tipoDeProductoAregistrar)
	{
	case 1:
		cout << "Ingrese el tipo De Alimento del hogar" << endl;
		cin >> tipoDeAlimento;
		cout << "Ingrese la fecha de caducidad" << endl;
		cin >> fechaDeCaducidad;
		alimento = new Alimento(id, nombre, detalle, cantidad, precio, fechaDeCaducidad, marca, tipoDeAlimento);
		alimento->añadirProveedor(proveedores[posProveedor]);
		alimento->agregarPrecioCompra(precioCompra);
		proveedores[posProveedor]->añadirProducto(alimento);
		productos.push_back(alimento);
		break;
	case 2:
		cout << "Ingrese el tipo De articulo del hogar" << endl;
		cin>>tipoDeArticulo;
		cout << "Ingrese el material de fabricacion del articulo del hogar" << endl;
		cin >> materialDeFabricacion;
		articuloDelHogar = new ArticuloDelHogar(id, nombre, detalle, cantidad, precio, marca, tipoDeArticulo, materialDeFabricacion);
		articuloDelHogar->añadirProveedor(proveedores[posProveedor]);

		articuloDelHogar->agregarPrecioCompra(precioCompra);
		proveedores[posProveedor]->añadirProducto(articuloDelHogar);
		productos.push_back(articuloDelHogar);
		break;
	case 3:
		cout << "Ingrese la fecha de caducidad" << endl;
		cin >> fechaDeCaducidad;
		cout << "Ingrese el tipo de producto" << endl;
		cin >> tipoDeProducto;
		cout << "Recomendaciones de uso" << endl;
		cin >> recomendacionesDeUso;
		cuidadoPersonal = new CuidadoPersonal(id, nombre, detalle, cantidad, precio, fechaDeCaducidad, marca, tipoDeProducto, recomendacionesDeUso);
		cuidadoPersonal->añadirProveedor(proveedores[posProveedor]);
		cuidadoPersonal->agregarPrecioCompra(precioCompra);
		proveedores[posProveedor]->añadirProducto(cuidadoPersonal);

		productos.push_back(cuidadoPersonal);
		break;
	default:
		break;
	}

}

void SuperMercado::actualizarCantidadProducto()
{
	int posProducto, cantidad;
	cout << "Ingrese -1 para salir" << endl;
	for (int i = 0; i < productos.size(); i++)
	{
		cout<<"["<<i<<"] ";
		cout << productos[i]->getDetalle();
		cout<<"Cantidad: " << productos[i]->getCantidad()<<endl;
		
	}
	cin >> posProducto;
	if (posProducto >= 0)
	{
		cout << "Ingrese la cantidad que desea aumentar" << endl;
		cin >> cantidad;
		productos[posProducto]->aumentarCantidad(cantidad);

	}
	
}

void SuperMercado::despedirEmpleado()
{
	int posicion;
	for (int i = 0; i < empleados.size(); i++)
	{
		cout << "[" << i << "] " << empleados[i]->getNombre() << endl;
		
	}
	cin >> posicion;
	if (posicion >= 0 && posicion < empleados.size()) {
		auto it = next(empleados.begin(), posicion); // Obtener iterador en la posición deseada
		empleados.erase(it); // Eliminar el elemento en la posición especificada
		cout << "Empleado Eliminado" << endl;
	}
	else {
		cout << "Posición inválida." << endl;
	}
}

void SuperMercado::cambiarEstadoDeEmpleado()
{
	int posicion;
	for (int i = 0; i < empleados.size(); i++)
	{
		cout << "[" << i << "] " << empleados[i]->getNombre() << endl;

	}
	cin >> posicion;
	empleados[posicion]->asignarEstado();

}

void SuperMercado::EstablecerCargoDeEmpleado()
{
	int posicion;
	for (int i = 0; i < empleados.size(); i++)
	{
		cout << "[" << i << "] " << empleados[i]->getNombre() << endl;

	}
	cin >> posicion;
	empleados[posicion]->asignarCargo();
}

void SuperMercado::calcularGanancias()
{
	float Ganancia=0, Gasto=0,Vendido=0,ganancia2=0;
	for (int i = 0; i < productos.size(); i++)
	{
		Vendido=productos[i]->getCantidadVendida()* productos[i]->getPrecioFinal()+ Vendido;
		Gasto=(productos[i]->getPrecioCompra()* productos[i]->getCantidad()) + (Gasto);
		ganancia2 = ((productos[i]->getPrecioFinal() - productos[i]->getPrecioCompra())*productos[i]->getCantidadVendida()) + ganancia2;
	}
	Ganancia = Vendido-Gasto;
	cout << "Gasto total compra productos: " << Gasto<<endl;
	cout << "Total de productos vendidos: " << Vendido << endl;
	cout << "Total de gasto recuperado: " << ganancia2 << endl;
	if (Ganancia <= 0)
	{
		cout << "No hay ganancias" << endl;
		cout << "La perdida es de: " << -Ganancia<<endl;
	}
	else
	{
		cout << "La ganancia Total es de: " << Ganancia << endl;

	}
}

void SuperMercado::gestionarInventario()
{
	int opcion = 1;
	cout << "GESTIONAR INVENTARIO" << endl;
	while (opcion != 0)
	{
		cout << "1. Registrar Producto" << endl;
		cout << "2. Registrar Proveedor" << endl;
		cout << "3. Aumentar Stock de un producto" << endl;

		cout << "0. SALIR" << endl;
		cin >> opcion;
		switch (opcion)
		{
		case 1:
			registrarProducto();
			break;
		case 2:
			registrarProveedor();
			break;
		case 3:
			actualizarCantidadProducto();
			break;
		default:
			break;
		}
	}
}


bool compararPorCantidadMayorAmenor( Producto* p1,  Producto* p2) {
	return p1->getCantidadVendida() > p2->getCantidadVendida();
}
bool compararPorCantidadMenorAmayor(Producto* p1, Producto* p2) {
	return p1->getCantidadVendida() < p2->getCantidadVendida();
}

void SuperMercado::mostrarProductosMenosVendidos() {
	sort(productos.begin(), productos.end(), compararPorCantidadMenorAmayor);
	mostrarProductosVendidosConCantidad();
}
void SuperMercado::mostrarProductosVendidosConCantidad()
{
	for (int i = 0; i < productos.size(); i++)
	{
		cout<<productos[i]->getDetalle()<<" ";
		cout << productos[i]->getCantidadVendida() << " ";
		cout << "cantidad: " << productos[i]->getCantidad() << endl;
	}
}
void SuperMercado::productosSinVender()
{
	for (int i = 0; i < productos.size(); i++)
	{
		if (productos[i]->getCantidadVendida() == 0)
		{
			cout << productos[i]->getDetalle() << " ";
			cout << productos[i]->getCantidadVendida() <<" ";
			cout << "cantidad: "<<productos[i]->getCantidad() << endl;

		}
		
	}
}
void SuperMercado::agregarDescuentoAproducto()
{
	int id, posProducto;
	float porcentajeDescuento;
	string fechaInicio;
	string fechaFin;
	cout << "Escoja un producto" << endl;
	for (int i = 0; i < productos.size(); i++)
	{
		cout<<"["<<i<<"] "<<productos[i]->getDetalle()<<endl;
	}
	cin >> posProducto;
	id = IdDescuentos.getId();
	cout << "Ingrese el porcentaje del Descuento --> 0.2 etc." << endl;
	cin >> porcentajeDescuento;
	cout << "Ingrese la fecha de inicio del Descuento" << endl;
	cin >> fechaInicio;
	cout << "Ingrese la fecha de fin del Descuento" << endl;
	cin >> fechaFin;
	Descuento* descuento = new Descuento(id,productos[posProducto],porcentajeDescuento,fechaInicio,fechaFin);
	descuentos.push_back(descuento);
}
void SuperMercado::mostrarProductosMasVendidos() {
	sort(productos.begin(), productos.end(), compararPorCantidadMayorAmenor);
	mostrarProductosVendidosConCantidad();
}
	

void SuperMercado::abrirCaja()
{
	cout << "Eliga una caja" << endl;
	int posCaja=0;
	for (int i = 0; i < cajasRegistradoras.size(); i++)
	{
		cout<<"["<<i<<"] "<< "id: "<<cajasRegistradoras[i]->getId()<<endl;
	}
	cin >> posCaja;
	cajasRegistradoras[posCaja]->abrirCaja();
}

SuperMercado::~SuperMercado()
{
		for (Empleado* empleado : empleados)
		{
			delete empleado;
		}
		for (Cliente* cliente : clientes)
		{
			delete cliente;
		}
		for (Producto* producto : productos)
		{
			delete producto;
		}
		for (Factura* factura : facturas)
		{
			delete factura;
		}
		for (CajaRegistradora* cajaRegistradora : cajasRegistradoras)
		{
			delete cajaRegistradora;
		}
		for (Descuento* descuento : descuentos)
		{
			delete descuento;
		}
}

void SuperMercado::loadData()
{
	Cliente* cliente1 = new Cliente(1,"Santiago ",20,"cbba cercado", 4235367,"santiago.lopez@gmail.com");
	Cliente* cliente2 = new Cliente(2, "Isabella ", 19, "cbba blanco galindo", 4203985, "isabella.garcia@gmail.com");
	Cliente* cliente3 = new Cliente(3, "Gabriel ", 25, "quillacollo", 4324357, "gabriel.martinez@gmail.com");
	Cliente* cliente4 = new Cliente(4, "Valentina ", 35, "cercado cuidad", 4376235, "valentina.rodriguez@gmail.com");


	Empleado* empleado1 = new Empleado(1, "Mateo", 12, "cbba", 8765432, "mateo.perez@gmail.com",2000);
	Empleado* empleado2 = new Empleado(2, "Sofía", 12, "cbba", 9123456, "sofia.torres@gmail.com", 1500);
	Empleado* empleado3 = new Empleado(3, "Lucas", 12, "cbba", 7654321, "lucas.ramirez@gmail.com", 1700);
	Empleado* empleado4 = new Empleado(4, "Camila", 12, "cbba", 6543219, "camila.herrera@gmail.com", 1200);


	CajaRegistradora* cajaRegistradora1 = new CajaRegistradora(1);
	CajaRegistradora* cajaRegistradora2 = new CajaRegistradora(2);


	Proveedor* proveedor1 = new Proveedor(1,"Proveedor de articulos","Quillacollo",4512454);
	Proveedor* proveedor2 = new Proveedor(2, "Proveedor de Alimento", "Cercado", 4538454);
	Proveedor* proveedor3 = new Proveedor(3, "Proveedor de Cuidado Personal", "Colcapirhua", 4576654);


	
	ArticuloDelHogar* articulo1 = new ArticuloDelHogar(1,"Lámpara de mesa","Lámpara de mesa con pantalla de tela", 5, 29.99,"MarcaA","Iluminación","Metal");
	ArticuloDelHogar* articulo2 = new ArticuloDelHogar(2, "Silla de comedor", "Silla de madera para comedor", 10, 49.99, "MarcaB", "Muebles", "Madera");
	ArticuloDelHogar* articulo3 = new ArticuloDelHogar(3, "Cortinas", "Cortinas opacas para bloquear la luz", 3, 39.99, "MarcaC", "Decoración", "Tela");
	ArticuloDelHogar* articulo4 = new ArticuloDelHogar(4, "Tabla de planchar", "Tabla de planchar plegable con soporte para plancha", 2, 19.99, "MarcaD", "Hogar", "Metal");
	articulo1->agregarPrecioCompra(27.99);
	articulo2->agregarPrecioCompra(47.99);
	articulo3->agregarPrecioCompra(37.99);
	articulo4->agregarPrecioCompra(17.99);
	


	Alimento* alimento1 = new Alimento(5,"Manzana","Manzana fresca y jugosa", 10, 1.99,"3 enero","MarcaA","Frutas");
	Alimento* alimento2 = new Alimento(6, "Leche", "Leche entera en envase de cartón", 5, 2.49, "3 enero", "MarcaB", "Lácteos");
	Alimento* alimento3 = new Alimento(7, "Arroz", "Arroz blanco de grano largo", 8, 1.79, "3 enero", "MarcaC", "Granos");
	Alimento* alimento4 = new Alimento(8, "Yogur", "Yogur natural sin azúcar", 12, 1.79, "3 enero", "MarcaD", "Lácteos");
	alimento1->agregarPrecioCompra(1.99);
	alimento2->agregarPrecioCompra(3.49);
	alimento3->agregarPrecioCompra(1.79);
	alimento4->agregarPrecioCompra(1.79);


	CuidadoPersonal* cuidado1 = new CuidadoPersonal(9,"Champú","Champú revitalizante para todo tipo de cabello", 10, 5.99,"5 enero","MarcaA","Cabello","Aplicar sobre el cabello húmedo y masajear suavemente. Enjuagar bien.");
	CuidadoPersonal* cuidado2 = new CuidadoPersonal(10, "Jabón líquido", "Jabón líquido antibacterial para manos", 8, 3.49, "5 enero", "MarcaB", "Manos", "Aplicar una pequeña cantidad sobre las manos, frotar hasta crear espuma y enjuagar con agua.");
	CuidadoPersonal* cuidado3 = new CuidadoPersonal(11, "Crema facial", "Crema hidratante para el rostro", 15, 12.99, "5 enero", "MarcaC", "Rostro", "Aplicar una pequeña cantidad en el rostro y cuello, masajear suavemente hasta su completa absorción.");
	CuidadoPersonal* cuidado4 = new CuidadoPersonal(12, "Desodorante", "Desodorante en barra con fragancia fresca", 6, 2.79, "5 enero", "MarcaD", "Axilas", "Aplicar sobre las axilas limpias y secas después del baño o según sea necesario.");
	cuidado1->agregarPrecioCompra(5.99);
	cuidado2->agregarPrecioCompra(3.49);
	cuidado3->agregarPrecioCompra(13.99);
	cuidado4->agregarPrecioCompra(2.79);
	

	clientes.push_back(cliente1);
	clientes.push_back(cliente2);
	clientes.push_back(cliente3);
	clientes.push_back(cliente4);

	empleados.push_back(empleado1);
	empleados.push_back(empleado2);
	empleados.push_back(empleado3);
	empleados.push_back(empleado4);

	cajasRegistradoras.push_back(cajaRegistradora1);
	cajasRegistradoras.push_back(cajaRegistradora2);


	proveedor1->añadirProducto(articulo1);
	proveedor1->añadirProducto(articulo2);
	proveedor1->añadirProducto(articulo3);
	proveedor1->añadirProducto(articulo4);

	articulo1->añadirProveedor(proveedor1);
	articulo2->añadirProveedor(proveedor1);
	articulo3->añadirProveedor(proveedor1);
	articulo4->añadirProveedor(proveedor1);


	proveedor2->añadirProducto(alimento1);
	proveedor2->añadirProducto(alimento2);
	proveedor2->añadirProducto(alimento3);
	proveedor2->añadirProducto(alimento4);

	alimento1->añadirProveedor(proveedor2);
	alimento2->añadirProveedor(proveedor2);
	alimento3->añadirProveedor(proveedor2);
	alimento4->añadirProveedor(proveedor2);



	proveedor3->añadirProducto(cuidado1);
	proveedor3->añadirProducto(cuidado2);
	proveedor3->añadirProducto(cuidado3);
	proveedor3->añadirProducto(cuidado4);

	cuidado1->añadirProveedor(proveedor3);
	cuidado2->añadirProveedor(proveedor3);
	cuidado3->añadirProveedor(proveedor3);
	cuidado4->añadirProveedor(proveedor3);



	
	productos.push_back(articulo1);
	productos.push_back(articulo2);
	productos.push_back(articulo3);
	productos.push_back(articulo4);



	productos.push_back(alimento1);
	productos.push_back(alimento2);
	productos.push_back(alimento3);
	productos.push_back(alimento4);


	productos.push_back(cuidado1);
	productos.push_back(cuidado2);
	productos.push_back(cuidado3);
	productos.push_back(cuidado4);

	proveedores.push_back(proveedor1);
	proveedores.push_back(proveedor2);
	proveedores.push_back(proveedor3);



	//Transaccion* transaccion = new Transaccion(1,"5 enero");
	//transaccion->agregarProducto(productos[1]);
	//transaccion->agregarProducto(productos[0]);
	//float monto = 0;
	//transaccion->setEmpleado(empleados[0]);
	//transaccion->setCliente(clientes[0]);
	//cajasRegistradoras[0]->agregarTransaccion(transaccion);
	//clientes[0]->añadirTransacccion(transaccion);
}

void SuperMercado::loadDataTXT()
{
	loadData1.recuperarDatos("productos.txt", "clientes.txt", "empleados.txt", "proveedores.txt", "cajas.txt", "facturas.txt", "transacciones1.txt", "transacciones2.txt");
	productos = loadData1.getProductos();
	clientes = loadData1.getClientes();
	empleados = loadData1.getEmpleados();
	proveedores = loadData1.getProveedor();
	cajasRegistradoras = loadData1.getCajas();
	facturas = loadData1.getFacturas();

	IdEmpleado.setId(empleados[empleados.size() - 1]->getId());


	//cout << "id: " << clientes.size() << endl;;
	//
	//for (int i = 0; i < clientes.size(); i++)
	//{
	//	cout<<"id: "<<clientes[i]->getId() << endl;;
	//}
	IdCliente.setId(clientes[clientes.size() - 1]->getId());
	IdProveedor.setId(proveedores[proveedores.size() - 1]->getId());
	IdProducto.setId(productos[productos.size() - 1]->getId());

	if (facturas.size() >= 1)
	{
		IdFactura.setId(facturas[facturas.size() - 1]->getId());
	}

	IdCajaRegistradora.setId(cajasRegistradoras[cajasRegistradoras.size() - 1]->getId());

	int pos1 = cajasRegistradoras[0]->getTransacciones().size() ;
	int pos2 = cajasRegistradoras[1]->getTransacciones().size() ;


	int pos3 = pos1 - 1;
	int pos4 = pos2 - 1;
	if (pos1 > 0 && pos2 > 0)
	{
		if (cajasRegistradoras[0]->getTransacciones()[pos1]->getId() > cajasRegistradoras[1]->getTransacciones()[pos2]->getId())
		{
			IdTransaccion.setId(cajasRegistradoras[0]->getTransacciones()[pos1]->getId());
		}
		else
		{
			IdTransaccion.setId(cajasRegistradoras[1]->getTransacciones()[pos2]->getId());
		}
	}

;

	//productos=LoadData::cargarDatos("productos.txt");
	//clientes=LoadData::recuperarClientes("clientes.txt");
	//empleados=LoadData::recuperarEmpleados("empleados.txt");
}

void SuperMercado::saveData()
{
	SaveData::guardarDatos("productos.txt",productos);
	SaveData::guardarClientes("clientes.txt", clientes);
	SaveData::guardarEmpleados("empleados.txt",empleados);

	SaveData::guardarProvedores("proveedores.txt", proveedores);
	SaveData::guardarCajas("cajas.txt", cajasRegistradoras);
	SaveData::guardarFacturas("facturas.txt",  facturas);


	SaveData::guardarTransacciones("transacciones1.txt", cajasRegistradoras[0]->getTransacciones());
	SaveData::guardarTransacciones("transacciones2.txt", cajasRegistradoras[1]->getTransacciones());


}


