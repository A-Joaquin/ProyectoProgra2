#pragma once
#include <string>
using namespace std;
class IEmpleado
{
public:
	virtual void asignarEstado() = 0;
	virtual void asignarHorario() = 0;
	virtual void asignarCargo() = 0;
	virtual string obtenerCargo()=0;
	virtual string obtenerEstado()=0;
	virtual void setCargo(string cargo) = 0;
	virtual void setSalario(float salario) = 0;
	virtual void setHorario(string horario) = 0;
	virtual void setEstado(string estado) = 0;
	virtual float getSalario() = 0;
	virtual string getHorario() = 0;
	virtual ~IEmpleado()
	{
	}
};

//class Empleado :public Persona
//{
//private:
//	Cargo cargo;
//	float salario = 0;
//	string horario;
//	Estado estado;
//public:
//	Empleado(int id, string nombre, int edad, string direccion, int telefono, string correoElectronico, float salario);
//	void asignarCargo();
//	void asignarHorario();
//	string obtenerCargo();
//
//	void asignarEstado();
//
//	string obtenerEstado();
//};
