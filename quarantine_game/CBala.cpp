#include "CBala.h"

CBala::CBala(){ 
	eliminar = false;
	dx = dy = 0;
	ind_x = ind_y = 0;
}
CBala::~CBala(){ }
void CBala::cambiar_categoria(categoria nuevo) { bombCateg = nuevo; }
categoria CBala::retornar_categoria() { return bombCateg; }
void CBala::cambiar_eliminar(bool nuevo) { eliminar = nuevo; }
bool CBala::retornar_eliminar() { return eliminar; }
void CBala::mover(BufferedGraphics^ buffer, Bitmap^ bmpBala) {
	
	if (ind_x < 4) ind_x++;
	else ind_x = 0;
	if (bombCateg == categ1) ind_y = 0;
	else if (bombCateg == categ2) ind_y = 1;
	else if (bombCateg == categ3) ind_y = 2;
	else if (bombCateg == categ4) ind_y = 3;

	if (x + dx < buffer->Graphics->VisibleClipBounds.Left || x + dx + w>buffer->Graphics->VisibleClipBounds.Right)
		eliminar = true;
	if (y + dy < buffer->Graphics->VisibleClipBounds.Top + 50 || y + dy + h>buffer->Graphics->VisibleClipBounds.Bottom)
		eliminar = true;

	dibujar(buffer, bmpBala);
}
void CBala::dibujar(BufferedGraphics^ buffer, Bitmap^ bmpBala) {
	int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
	int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
	w = bmpBala->Width / 5;
	h = bmpBala->Height / 4;
	Rectangle porcionAUsar = Rectangle(ind_x * w, ind_y * h, w, h);
	Rectangle aumento = Rectangle(x, y, w * 0.7, h * 0.7);
	buffer->Graphics->DrawImage(bmpBala, aumento, porcionAUsar, GraphicsUnit::Pixel);

	if (x + dx > 0 && x + dx + w < MAX_W)
		x += dx;
	if (y + dy > 0 && y + dy + h <= MAX_H )
		y += dy;
}