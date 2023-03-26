#pragma once
#include "NPC.h"
class CPlataforma :
	public NPC
{
private:

public:
	CPlataforma();
	~CPlataforma();
	void dibujar_plataforma(BufferedGraphics^ buffer, Bitmap^ bmpPlataforma, int posx, int posy);
};

