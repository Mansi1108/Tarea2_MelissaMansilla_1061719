#include "Carrera.h"

Carrera::Carrera()
{
}


Carrera::~Carrera()
{
}

void Carrera::CrearPista() {
	//Se lleva a cabo la construccion del vector y su recorrido tambien
	//Se especifica el punto de partida de los dos animales, ya que parten del mismo lugar.
	for (int i = 0; i <= 70; i++)
	{
		RielL[i] = i + 1;
		RielH[i] = i + 1;
	}

	PunL = &RielL[0];
	PunH = &RielL[0];
}

void Carrera::PH(int n) {
	//Descripccion de los movimientos a base de la tabla especificada, con sus conjuntas validaciones
	//Siempre tomando en cuenta cuando se vuelven negativos.
	switch (n)
	{
	case (1):
	case (2):
	case (3):
	case (4):
	case (5):
		if ((*PunH + 3) >= 70) {
			PunH = &RielH[69];
		}
		else {
			PunH = PunH + 3;
		}
		break;
	case (6):
	case (7):
		if ((*PunH -6) < 1) {
			PunH = &RielH[0];
		}
		else {
			PunH = PunH - 6;
		}
		break;
	case (8):
	case (9):
	case (10):
		if ((*PunH + 1) >= 70) {
			PunH = &RielH[69];
		}
		else {
			PunH = PunH + 1;
		}
		break;
	}
}
int Carrera::PosL() {
	return *PunL;
	//Nos devuelve la dirección de la posicion temporal de la liebre en cada iteracion.
}
int Carrera::PosH() {
	return *PunH;
	//Nos devuelve la dirección de la posicion temporal de la tortuga en cada iteracion.
}
void Carrera::PL(int n) {
	//Descripccion de los movimientos a base de la tabla especificada, con sus conjuntas validaciones
	//Siempre tomando en cuenta cuando se vuelven negativos.
	switch (n)
	{
	case (1):
	case (2):
		PunL = PunL;
		break;
	case (3):
	case (4):
		if ((*PunL + 9) >= 70) {
			PunL = &RielL[69];
		}
		else {
			PunL = PunL + 9;
		}
		break;
	case (5):
		if ((*PunL - 12) < 1) {
			PunL = &RielL[0];
		}
		else {
			PunL = PunL - 12;
		}
		break;
	case (6):
	case (7):
	case (8):
		if ((*PunL + 1) >= 70) {
			PunL = &RielL[69];
		}
		else {
			PunL = PunL + 1;
		}
		break;
	case (9):
	case (10):
		if ((*PunL -2 ) < 1) {
			PunL = &RielL[0];
		}
		else {
			PunL = PunL - 2;
		}
		break;
	}
}