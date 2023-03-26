#pragma once
#include "Adversario.h"
#include "CReloj.h"
#include "CBala.h"
class ArrAdversarios
{
private:
	int maxBalas;
	int tiemPrueba;
	int tiemPrueba2;
	int cant_max;
	Adversario** arreglo;
	int* tmn;
	bool generado;
	bool generado2;
	CBala** arregloB;
	int* cantB;
	int antecesor;
	bool ingresoB;
public:
	ArrAdversarios();
	~ArrAdversarios();
	CBala* retornar_bala(int indice);
	Adversario* retornar_adversario(int indice);
	void cambiar_cantMax(int nuevo);
	void cambiar_tiempPrueba(int nuevo);
	int retornar_tmn();
	bool retornar_generado();
	void cambiar_generado(bool nuevo);
	bool retornar_generado2();
	int retornar_maxBalas();
	void cambiar_cantB(int nuevo);
	int retornar_cantB();
	void cambiar_generado2(bool nuevo);
	void insertar_adversarios(categoriaA _categ, int _tipoEnem, int tipoMundo, int MAX_W, int MAX_H, int tiempSeg);
	void eliminar_adversarios();
	void disparar(int x_jug, int _seg);
	void mover_balas(BufferedGraphics^ buffer, Bitmap^ bmpBala);
	void eliminar_balas();
	void cambiar_ingresoB(bool nuevo);
};

