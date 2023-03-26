#include "CIntrucciones.h"

CIntrucciones::CIntrucciones() {
	ind_x = ind_y = 0;
	ini_c = 0;
	fin_c = 5;
	ini_f = 0;
	fin_f = 10;
	dx = dy = 0;
}
CIntrucciones::~CIntrucciones(){}
void CIntrucciones::cambiar_iniC(int nuevo) { ini_c = nuevo; }
void CIntrucciones::cambiar_iniF(int nuevo) { ini_f = nuevo; }
void CIntrucciones::cambiar_finC(int nuevo) { fin_c = nuevo; }
void CIntrucciones::cambiar_finF(int nuevo) { fin_f = nuevo; }
int CIntrucciones::retornar_iniC() { return ini_c; }
int CIntrucciones::retornar_iniF() { return ini_f; }
int CIntrucciones::retornar_finC() { return fin_c; }
int CIntrucciones::retornar_finF() { return fin_f; }
void CIntrucciones::dibujar_instrucciones(Graphics^ g, Bitmap^ bmpMenu) {
	w = bmpMenu->Width / 6;
	h = bmpMenu->Height / 11;
	Rectangle porcionAUsar = Rectangle(ind_x * w, ind_y * h, w, h);
	Rectangle aumentoBMP = Rectangle(x, y, w * 0.6, h *0.6);
	g->DrawImage(bmpMenu, aumentoBMP, porcionAUsar, GraphicsUnit::Pixel);
	if (ind_y >= 6) _sleep(200);
}
void CIntrucciones::mover_instrucciones(Graphics^ g, Bitmap^ bmpMenu) {
	int MAX_W = g->VisibleClipBounds.Width;
	int MAX_H = g->VisibleClipBounds.Height;
	x = (MAX_W / 2) - (w * 0.6 / 2);
	y = (MAX_H / 2) - (h * 0.6 / 2);
	if (ind_x >= 0 && ind_x < fin_c) {
		ind_x++;
	}
	else {
		ind_x = 0;
		if (ind_y == fin_f) 
			ind_y = ini_f;
		else ind_y++;
	}
	dibujar_instrucciones(g, bmpMenu);
}
