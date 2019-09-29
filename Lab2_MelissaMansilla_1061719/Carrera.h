#pragma once
class Carrera
{
	int RielL[70];
	int RielH[70];
	int* PunL;
	int* PunH;

public:
	Carrera();
	~Carrera();
	void Carrera::CrearPista();
	//La variable x es el numero mandado por referencia del numero random.
	void Carrera::PH(int x);
	void Carrera::PL(int x);
	//Se crean como funciones para devolver los punteros de las posiciones temporales.
	int Carrera::PosL();
	int Carrera::PosH();
};
