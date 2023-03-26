#pragma once
#include "NPC.h"
enum categoria { categ1, categ2, categ3, categ4 };
class CBala : public NPC
{
private:
	bool eliminar;
	categoria bombCateg;
public:
	CBala();
	~CBala();
	void cambiar_categoria(categoria nuevo);
	categoria retornar_categoria();
	void cambiar_eliminar(bool nuevo);
	bool retornar_eliminar();
	void mover(BufferedGraphics^ buffer, Bitmap^ bmpBala);
	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmpBala);
};

