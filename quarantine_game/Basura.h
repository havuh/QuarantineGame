#pragma once
#include "NPC.h"
class Basura :
	public NPC
{
private:
	bool eliminar_basura;
public:
	Basura();
	~Basura();
	void cambiar_eliminarBasura(bool nuevo);
	bool retornar_eliminarBasura();
	void dibujar_basura(BufferedGraphics^ buffer, Bitmap^ bmpBasura);
};

