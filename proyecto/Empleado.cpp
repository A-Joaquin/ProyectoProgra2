#include "Empleado.h"

Empleado::Empleado():Persona()
{
}

Empleado::Empleado(int id, string nombre, int edad, string direccion, int telefono, string correoElectronico, float salario) :Persona(id, nombre, edad, direccion, telefono, correoElectronico)
{
	this->salario = salario;
	this->estado = activo;
	this->cargo = Atencion;
}

void Empleado::asignarCargo() 
{
	int cargo = 5;
	cout << "asignar Cargo" << endl;
	cout << "0. Gerencia" << endl;
	cout << "1. Finanzas" << endl;
	cout << "2. Operaciones" << endl;
	cout << "3. Atencion" << endl;
	cin >> cargo;
	this->cargo = (Cargo)cargo;
}

void Empleado::asignarHorario() {
	cout << "asignar horario" << endl;
	cin >> this->horario;
}

string Empleado::obtenerCargo() 
{
	string getCargo;
	switch ((int)this->cargo)
	{
	case 0:
		getCargo = "Gerencia";
		break;
	case 1:
		getCargo = "Finanzas";
		break;
	case 2:
		getCargo = "Operaciones";
		break;
	case 3:
		getCargo = "Atencion";
		break;
	default:
		getCargo = "Sin cargo";
		break;
	}
	return getCargo;
}

void Empleado::setCargo(string cargo)
{
	if (cargo == "Gerencia")
	{
		this->cargo = Cargo::Gerencia;
	
	}
	if (cargo == "Finanzas")
	{
		this->cargo = Cargo::Finanzas;
	}
	if (cargo == "Operaciones")
	{
		this->cargo = Cargo::Operaciones;
	}
	if (cargo == "Atencion")
	{
		this->cargo = Cargo::Atencion;
	}
}

void Empleado::asignarEstado() 
{
	int estado = 5;
	cout << "asignar estado" << endl;
	cout << "0. activo" << endl;
	cout << "1. vacaciones" << endl;
	cout << "2. despedido" << endl;
	cout << "3. jubilado" << endl;
	cout << "4. Baja Por Enfermedad" << endl;
	cin >> estado;
	this->estado = (Estado)estado;
}

void Empleado::setSalario(float salario)
{
	this->salario = salario;
}

void Empleado::setHorario(string horario)
{
	this->horario = horario;
}

void Empleado::setEstado(string estado)
{
	if (estado == "vacaciones")
	{
		this->estado = Estado::vacaciones;
	}
	if (estado == "despedido")
	{
		this->estado = Estado::despedido;
	}
	if (estado == "jubilado")
	{
		this->estado = Estado::jubilado;
	}
	if (estado == "BajaPorEnfermedad")
	{
		this->estado = Estado::BajaPorEnfermedad;
	}

}

string Empleado::obtenerEstado() 
{
	string getEstado;
	switch ((int)this->estado)
	{
	case 0:
		getEstado = "activo";
		break;
	case 1:
		getEstado = "vacaciones";
		break;
	case 2:
		getEstado = "despedido";
		break;
	case 3:
		getEstado = "jubilado";
		break;
	case 4:
		getEstado = "Baja Por Enfermedad";
		break;
	default:
		getEstado = "Sin cargo";
		break;
	}
	return getEstado;
}

float Empleado::getSalario()
{
	return salario;
}

string Empleado::getHorario()
{
	return horario;
}
