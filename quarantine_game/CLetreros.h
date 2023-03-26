#pragma once
#include "NPC.h"
class CLetreros :
	public NPC
{
private:
	int ini_f, fin_f;
	bool ingreso;
	bool ingreso2;
	bool ingreso3;
public:
	CLetreros();
	~CLetreros();
	void cambiar_iniF(int nuevo);
	void cambiar_finF(int nuevo);
	void cambiar_indY(int nuevo);
	int retornar_iniF();
	int retornar_finF();
	void dibujar_letrero(BufferedGraphics^ buffer, Bitmap^ bmpLetreros);
	void mover_letreroYouLose(BufferedGraphics^ buffer, Bitmap^ bmpLetreros);
	void mover_letreroNext(BufferedGraphics^ buffer, Bitmap^ bmpLetreros);
	void mover_letreroYouWin(BufferedGraphics^ buffer, Bitmap^ bmpLetreros);
};

