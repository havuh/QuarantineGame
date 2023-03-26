#include "CPlataforma.h"

CPlataforma::CPlataforma() {
	dx = dy = 0;
	ind_x = 0;
	ind_y = 0;
}
CPlataforma::~CPlataforma(){}
void CPlataforma::dibujar_plataforma(BufferedGraphics^ buffer, Bitmap^ bmpPlataforma, int posx, int posy) {
	w = bmpPlataforma->Width;
	h = bmpPlataforma->Height / 5;
	x = posx - 30;
	y = posy + 180;

	if (ind_y >= 0 && ind_y < 5) ind_y++;
	else ind_y = 0;

	Rectangle porcionAUsar = Rectangle(ind_x * w, ind_y * h, w, h);
	Rectangle aumentoBMP = Rectangle(x, y, w * 0.7, h *0.7);
	buffer->Graphics->DrawImage(bmpPlataforma, aumentoBMP, porcionAUsar, GraphicsUnit::Pixel);
}