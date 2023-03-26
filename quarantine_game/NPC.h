#pragma once
#include <iostream>
using namespace System::Drawing;
enum Direcciones { ninguno, abajo, arriba, izquierda, derecha };
class NPC
{
protected:
	int x, y, dx, dy, w, h;
	int ind_x, ind_y;
public:
	NPC();
	~NPC();
	void cambiar_x(int nuevo);
	void cambiar_y(int nuevo);
	void cambiar_dx(int nuevo);
	void cambiar_dy(int nuevo);
	void cambiar_w(int nuevo);
	void cambiar_h(int nuevo);
	void cambiar_indX(int nuevo);
	void cambiar_indY(int nuevo);
	int retornar_x();
	int retornar_y();
	int retornar_dx();
	int retornar_dy();
	int retornar_w();
	int retornar_h();
	int retornar_indX();
	int retornar_indY();
};

