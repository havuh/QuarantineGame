#pragma once
#include "Basura.h"
class ArrBasura
{
private:
	int iniciar;
	Basura** arreglo;
	int* tmn;
	int cantMax;
public:
	ArrBasura(int cant_MAX);
	~ArrBasura();
	void init(int cant_MAX);
	void insertar_basura(BufferedGraphics^ buffer, Bitmap^ bmpBasura);
	void dibujar_todos(BufferedGraphics^ buffer, Bitmap^ bmpBasura);
	void eliminar_basura();
	int retornar_tmn();
	Basura* retornar_basura(int indice);
};

