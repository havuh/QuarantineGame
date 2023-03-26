#include "CLetreros.h"

CLetreros::CLetreros(){
	ind_x = ind_y = 0;
	dx = dy = 0;
	ingreso = ingreso2 = ingreso3 = false;
}
CLetreros::~CLetreros(){}
void CLetreros::cambiar_iniF(int nuevo) { ini_f = nuevo; }
void CLetreros::cambiar_finF(int nuevo) { fin_f = nuevo; }
void CLetreros::cambiar_indY(int nuevo) { ind_y = nuevo; }
int CLetreros::retornar_iniF() { return ini_f; }
int CLetreros::retornar_finF() { return fin_f; }
void CLetreros::dibujar_letrero(BufferedGraphics^ buffer, Bitmap^ bmpLetreros) {
	Rectangle porcionAUsar = Rectangle(w * ind_x, h * ind_y, w, h);
	Rectangle aumentoBMP = Rectangle(x, y, w, h);
	buffer->Graphics->DrawImage(bmpLetreros, aumentoBMP, porcionAUsar, GraphicsUnit::Pixel);
}
void CLetreros::mover_letreroYouLose(BufferedGraphics^ buffer, Bitmap^ bmpLetreros) {
	if (ingreso == false) {
		w = bmpLetreros->Width;
		h = bmpLetreros->Height / 15;
		int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
		int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
		x = (MAX_W / 2) - (w / 2);
		y = (MAX_H / 2) - (h / 2);
		ini_f = 8;
		fin_f = 14;
		ind_y = ini_f;
		ingreso = true;
	}
	if (ind_y >= ini_f && ind_y < fin_f) {
		ind_y++;
	}
	else {
		ind_y = fin_f;
	}
	dibujar_letrero(buffer, bmpLetreros);
}
void CLetreros::mover_letreroYouWin(BufferedGraphics^ buffer, Bitmap^ bmpLetreros) {
	if (ingreso2 == false) {
		w = bmpLetreros->Width;
		h = bmpLetreros->Height / 15;
		int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
		int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
		x = (MAX_W / 2) - (w / 2);
		y = (MAX_H / 2) - (h / 2);
		ini_f = 2;
		fin_f = 7;
		ind_y = ini_f;
		ingreso2 = true;
	}
	if (ind_y >= ini_f && ind_y < fin_f) {
		ind_y++;
	}
	else {
		ind_y = fin_f;
	}
	dibujar_letrero(buffer, bmpLetreros);
}
void CLetreros::mover_letreroNext(BufferedGraphics^ buffer, Bitmap^ bmpLetreros) {
	if (ingreso3 == false) {
		w = bmpLetreros->Width;
		h = bmpLetreros->Height / 6;
		int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
		int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
		x = MAX_W - w;
		y = (MAX_H / 2) - (h / 2);
		ini_f = 0;
		fin_f = 5;
		ind_y = ini_f;
		ingreso3 = true;
	}
	if (ind_y >= ini_f && ind_y < fin_f) {
		ind_y++;
	}
	else {
		ind_y = ini_f;
	}
	dibujar_letrero(buffer, bmpLetreros);
}