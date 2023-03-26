#include "Adversario.h"

Adversario::Adversario() {
	vidas = 2 + rand() % 2;
	recibio_pdisp = false;
	eliminar = false;
	dx = dy = 0;
	eliminando = false;
	desacMovimiento = false;
}
Adversario::~Adversario() { }
void Adversario::cambiar_eliminando(bool nuevo) { eliminando = nuevo; }
void Adversario::cambiar_vidas(int nuevo) { vidas = nuevo; }
void Adversario::cambiar_categorias(categoriaA nuevo) { categ = nuevo; }
void Adversario::cambiar_avance(int nuevo) { avance = nuevo; }
void Adversario::cambiar_recibio_disp(bool nuevo) { recibio_pdisp = nuevo; }
void Adversario::cambiar_tipoEnem(int nuevo) { tipoEnem = nuevo; }
void Adversario::cambiar_eliminar(bool nuevo) { eliminar = nuevo; }
void Adversario::cambiar_finC(int nuevo) { ini_c = nuevo; }
void Adversario::cambiar_desacMovimiento(bool nuevo) { desacMovimiento = nuevo; }
void Adversario::cambiar_tipoDMundo(int nuevo) { tipoMundo = nuevo; }
int Adversario::retornar_vidas() { return vidas; }
categoriaA Adversario::retornar_categoria() { return categ; }
Direcciones Adversario::retornar_ultimaDireccion() { return ultimaDireccion; }
int Adversario::retornar_avance() { return avance; }
bool Adversario::retornar_recibio_disp() { return recibio_pdisp; }
int Adversario::retornar_tipoEnem() { return tipoEnem; }
bool Adversario::retornar_eliminando() { return eliminando; }
bool Adversario::retornar_eliminar() { return eliminar; }
int Adversario::retornar_finC() { return fin_c; }
void Adversario::mover_adversario(BufferedGraphics^ buffer, Bitmap^ bmp, Bitmap^ bmp2, Direcciones direccion) {
	if (desacMovimiento == false) {
		if (categ == asintomatico && recibio_pdisp == true) {
			ini_c = 0; fin_c = 2;
			if (cambio == 0) {
				ind_x = ini_c; cambio = 1;
			}
		}
		else if (categ == asintomatico && recibio_pdisp == false) {
			ini_c = 3; fin_c = 5;
			if (cambio == 1) {
				ind_x = ini_c; cambio = 2;
			}
		}
		else if (categ == saludable && recibio_pdisp == true) {
			ini_c = 6; fin_c = 8;
			if (cambio == 0) {
				ind_x = ini_c; cambio = 1;
			}
		}
		else if (categ == saludable && recibio_pdisp == false) {
			ini_c = 9; fin_c = 11;
			if (cambio == 1) {
				ind_x = ini_c; cambio = 2;
			}
		}
		if (eliminando == true) {
			fin_c = fin_c + 1;
		}
		switch (direccion)
		{
		case arriba:
			ind_y = 3;
			if (ind_x >= ini_c && ind_x < fin_c) ind_x++;
			else ind_x = ini_c;
			dx = 0;
			dy = -avance;
			ultimaDireccion = arriba;
			break;
		case abajo:
			ind_y = 2;
			if (ind_x >= ini_c && ind_x < fin_c) ind_x++;
			else ind_x = ini_c;
			dx = 0;
			dy = avance;
			ultimaDireccion = abajo;
			break;
		case izquierda:
			ind_y = 0;
			if (ind_x >= ini_c && ind_x < fin_c) ind_x++;
			else ind_x = ini_c;
			dx = -avance;
			dy = 0;
			ultimaDireccion = izquierda;
			break;
		case derecha:
			ind_y = 1;
			if (ind_x >= ini_c && ind_x < fin_c) ind_x++;
			else ind_x = ini_c;
			dx = avance;
			dy = 0;
			ultimaDireccion = derecha;
			break;
		case ninguno:
			dx = dy = 0;
			switch (ultimaDireccion) {
			case arriba:
				ind_x = ini_c; ind_y = 3;
				break;
			case abajo:
				ind_x = ini_c; ind_y = 2;
				break;
			case izquierda:
				ind_x = ini_c; ind_y = 0;
				break;
			case derecha:
				ind_x = ini_c; ind_y = 1;
				break;
			}
		}
		ultimaDireccion = direccion;
		x += dx;
		y += dy;
	}
	if (tipoMundo == 1)
		dibujar_adversario(buffer, bmp2);
	else
		dibujar_adversario(buffer, bmp);
}
void Adversario::dibujar_adversario(BufferedGraphics^ buffer, Bitmap^ bmp) {
	w = bmp->Width / 12;
	h = bmp->Height / 4;
	int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
	int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
	Rectangle porcionAUsar = Rectangle(w * ind_x, h * ind_y, w, h);
	Rectangle aumentoBMP = Rectangle(x, y, w * 0.7, h * 0.7);
	buffer->Graphics->DrawImage(bmp, aumentoBMP, porcionAUsar, GraphicsUnit::Pixel);
}


