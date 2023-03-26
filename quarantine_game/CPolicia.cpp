#include "CPolicia.h"

CPolicia::CPolicia() {
	init();
}
void CPolicia::init() {
	cantidad = 0;
	x = 1900;
	dx = dy = 5;
	direccion = izquierda;
	ind_x = 0;
}
CPolicia::~CPolicia(){}
void CPolicia::cambiar_cantidad(int nuevo) { cantidad = nuevo; }
int CPolicia::retornar_cantidad() { return cantidad; }
void CPolicia::dibujar_policia(BufferedGraphics^ buffer, Bitmap^ bmpPolicia) {
	w = bmpPolicia->Width / 3;
	h = bmpPolicia->Height / 4;
	Rectangle porcionAUsar = Rectangle(ind_x * w, ind_y * h, w, h);
	Rectangle aumentoBMP = Rectangle(x, y, w * 0.8, h * 0.8);
	buffer->Graphics->DrawImage(bmpPolicia, aumentoBMP, porcionAUsar, GraphicsUnit::Pixel);
}
void CPolicia::mover_policia(BufferedGraphics^ buffer, Bitmap^ bmpPolicia) {
	int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
	int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
	y = 2*(buffer->Graphics->VisibleClipBounds.Height / 4);
	if (x > 3 * (MAX_W / 4)) {
		x -= dx;
		direccion = izquierda;
	}
	else {
		if (y > 3 * (MAX_H / 4)) {
			y -= dy; direccion = arriba;
		}
		else {
			if (direccion == arriba || direccion == izquierda) {
				direccion = abajo; ind_x = 0;
			}
			else {
				direccion = ninguno; ind_x = 0;
			}
			dx = dy = 0;
		}
	}
	switch (direccion) {
	case izquierda:
		ind_y = 3;
		if (ind_x >= 0 && ind_x < 2)ind_x++;
		else ind_x = 0;
		break;
	case derecha:
		ind_y = 1;
		if (ind_x >= 0 && ind_x < 2)ind_x++;
		else ind_x = 0;
		break;
	case abajo:
		ind_y = 0;
		if (ind_x >= 0 && ind_x < 2)ind_x++;
		else ind_x = 0;
		break;
	case arriba:
		ind_y = 2;
		if (ind_x >= 0 && ind_x < 2)ind_x++;
		else ind_x = 0;
		break;
	}
	dibujar_policia(buffer, bmpPolicia);
}