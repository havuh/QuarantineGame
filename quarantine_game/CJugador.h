#pragma once
#include <iostream>
#include "CBala.h"
#include "CPlataforma.h"
using namespace System::Drawing;

class CJugador
{
private:
	int x, y, dx, dy, ancho, alto;
	int ind_x, ind_y;
	Direcciones ultimaDireccion;
	int vidas;
	int MAX_vida;
	int puntaje;
	int disp_max, disp_rea;
	int avance;
	CBala** arrBala;
	int* cantBala;
	int max_balas;
	int cantBasura;
	CPlataforma* plataformJug;
	bool desact_controles;
	bool desact_dibujo;
	bool desact_plataforma;

public:
	CJugador(int _vidas, int _x, int _y);
	~CJugador();
	Direcciones direccion;
	void cambiar_x(int nuevo);
	void cambiar_y(int nuevo);
	void cambiar_dx(int nuevo);
	void cambiar_dy(int nuevo);
	void cambiar_w(int nuevo);
	void cambiar_h(int nuevo);
	void cambiar_indiceX(int nuevo);
	void cambiar_indiceY(int nuevo);
	void cambiar_ultimaDireccion(Direcciones nuevo);
	void cambiar_vidas(int nuevo);
	void cambiar_puntaje(int nuevo);
	void cambiar_dispMax(int nuevo);
	void cambiar_dispRea(int nuevo);
	void cambiar_cantBasura(int nuevo);
	void cambiar_desacControles(bool nuevo);
	void cambiar_desacDibujo(bool nuevo);
	void cambiar_desacPlataforma(bool nuevo);
	int retornar_x();
	int retornar_y();
	int retornar_dx();
	int retornar_dy();
	int retornar_w();
	int retornar_h();
	int retornar_indiceX();
	int retornar_indiceY();
	int retornar_cantB();
	Direcciones retornar_ultimaDireccion();
	int retonar_vidas();
	int retornar_puntaje();
	int retornar_dispMax();
	int retornar_dispRea();
	int retornar_cantBasura();
	CBala* retornar_bala(int indice);
	CPlataforma* retornar_plataforma();
	bool retornar_desacControles();

	void dibujar_personaje(BufferedGraphics^ buffer, Bitmap^ bmp, int MAX_W, int MAX_H);
	void mover_personaje(BufferedGraphics^ buffer, Bitmap^ bmp, int MAX_W, int MAX_H, Bitmap^ bmpBala, Bitmap^ bmpPlataforma);
	void disparar(categoria _categoria);
	void mover_balas(BufferedGraphics^ buffer, Bitmap^ bmpBala);
	void mostrar_vidas(BufferedGraphics^ buffer, Bitmap^ bmp_Vidas, int MAX_W, int MAX_H);
};

