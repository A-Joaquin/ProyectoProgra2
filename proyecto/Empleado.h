#pragma once
#include "Persona.h"
#include "IEmpleado.h"
enum Cargo
{
	Gerencia,
	Finanzas,
	Operaciones,
	Atencion
};
enum Estado
{
	activo,
	vacaciones,
	despedido,
	jubilado,
	BajaPorEnfermedad
};
class Empleado:public Persona,public IEmpleado
{
private:
	Cargo cargo;
	float salario=0;
	string horario;
	Estado estado;
public:
	Empleado();
	Empleado(int id, string nombre, int edad, string direccion, int telefono, string correoElectronico,float salario);
	void asignarCargo() override;
	void asignarHorario() override;
	string obtenerCargo() override;
	void setCargo(string cargo) override;
	void asignarEstado() override;
	void setSalario(float salario) override;
	void setHorario(string horario) override;
	void setEstado(string estado) override;
	string obtenerEstado() override;
	float getSalario() override;
	string getHorario() override;
};

