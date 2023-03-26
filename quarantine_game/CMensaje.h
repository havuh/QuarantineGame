#pragma once
#include "NPC.h"
class CMensaje :
	public NPC
{
private:
	bool seGenero;
	bool desacMensaje;
public:
	CMensaje();
	~CMensaje();
	void cambiar_seGenero(bool nuevo);
	void cambiar_desacMensaje(bool nuevo);
	bool retornar_seGenero();
	void dibujar_mensaje(BufferedGraphics^ buffer, Bitmap^ bmpMensaje, int x_pers, int y_pers);
	void generar_mensaje(int x_pers, int y_pers);
};

