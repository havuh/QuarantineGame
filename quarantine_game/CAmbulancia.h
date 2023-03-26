#pragma once
#include "NPC.h"
class CAmbulancia :
	public NPC
{
private:
	int cantidad;
public:
	CAmbulancia();
	~CAmbulancia();
	void cambiar_cantidad(int nuevo);
	int retornar_cantidad();
	void dibujar_ambulancia(BufferedGraphics^ buffer, Bitmap^ bmpAmbulancia);
	void mover_ambulancia(BufferedGraphics^ buffer, Bitmap^ bmpAmbulancia);
};

