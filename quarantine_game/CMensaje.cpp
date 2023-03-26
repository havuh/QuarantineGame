#include "CMensaje.h"

CMensaje::CMensaje(){
	dx = dy = 0;
	ind_x = 0;
	ind_y = 0;
	seGenero = false;
	desacMensaje = false;
}
CMensaje::~CMensaje(){}
void CMensaje::cambiar_seGenero(bool nuevo) { seGenero = nuevo; }
void CMensaje::cambiar_desacMensaje(bool nuevo) { desacMensaje = nuevo; }
bool CMensaje::retornar_seGenero() { return seGenero; }
void CMensaje::dibujar_mensaje(BufferedGraphics^ buffer, Bitmap^ bmpMensaje, int x_pers, int y_pers) {
	if (seGenero == true && desacMensaje == false) {
		w = bmpMensaje->Width;
		h = bmpMensaje->Height / 8;
		x = x_pers - 70;
		y = y_pers - 60;
		Rectangle porcionAUsar = Rectangle(ind_x * w, ind_y * h, w, h);
		Rectangle aumentoBMP = Rectangle(x, y, w, h);
		buffer->Graphics->DrawImage(bmpMensaje, aumentoBMP, porcionAUsar, GraphicsUnit::Pixel);
	}
}
void CMensaje::generar_mensaje(int x_pers, int y_pers) {
	ind_y = 1 + rand() % 8;
}