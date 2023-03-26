#pragma once
#include "NPC.h"
class CPolicia :
	public NPC
{
private:
	int cantidad;
	Direcciones direccion;
	
public:
	CPolicia();
	~CPolicia();
	void init();
	void cambiar_cantidad(int nuevo);
	int retornar_cantidad();
	void dibujar_policia(BufferedGraphics^ buffer, Bitmap^ bmpPolicia);
	void mover_policia(BufferedGraphics^ buffer, Bitmap^ bmpPolicia);
};

