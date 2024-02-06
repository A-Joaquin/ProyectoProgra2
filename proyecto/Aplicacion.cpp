#include "Aplicacion.h"

void Aplicacion::start()
{
	supermercado.loadDataTXT();
	supermercado.menu();
}
