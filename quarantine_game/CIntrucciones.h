#pragma once
#include "NPC.h"
class CIntrucciones : public NPC
{
private:
	int ini_c, fin_c, ini_f, fin_f;
public:
	CIntrucciones();
	~CIntrucciones();
	void cambiar_iniC(int nuevo);
	void cambiar_iniF(int nuevo);
	void cambiar_finC(int nuevo);
	void cambiar_finF(int nuevo);
	int retornar_iniC();
	int retornar_iniF();
	int retornar_finC();
	int retornar_finF();
	void dibujar_instrucciones(Graphics^ g, Bitmap^ bmpMenu);
	void mover_instrucciones(Graphics^ g, Bitmap^ bmpMenu);
};

