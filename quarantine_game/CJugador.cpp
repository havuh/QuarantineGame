#include "CJugador.h"

CJugador::CJugador(int _vidas, int _x, int _y) {
	vidas = _vidas; 
	MAX_vida = 5;
	ancho = 150;
	alto = 292;
	x = _x;
	y = _y;
	ultimaDireccion = derecha;
	direccion = ninguno;
	puntaje = 0;
	disp_max = 1;
	disp_rea = 0;
	ind_x = 0;
	ind_y = 0;
	dx = 0;
	dy = 0;
	avance = 15;
	max_balas = 5;
	cantBala = new int;
	*cantBala = 0;
	cantBasura = 0;
	plataformJug = new CPlataforma();
	desact_controles = desact_dibujo = desact_plataforma = false;
}
CJugador::~CJugador(){ 
	for (int i = 0; i < *cantBala; i++)
		delete arrBala[i];
	delete cantBala;
}
void CJugador::cambiar_x(int nuevo) { x = nuevo; }
void CJugador::cambiar_y(int nuevo) { y = nuevo; }
void CJugador::cambiar_dx(int nuevo) { dx = nuevo; }
void CJugador::cambiar_dy(int nuevo) { dy = nuevo; }
void CJugador::cambiar_w(int nuevo) { ancho = nuevo; }
void CJugador::cambiar_h(int nuevo) { alto = nuevo; }
void CJugador::cambiar_indiceX(int nuevo) { ind_x = nuevo; }
void CJugador::cambiar_indiceY(int nuevo) { ind_y = nuevo; }
void CJugador::cambiar_ultimaDireccion(Direcciones nuevo) { ultimaDireccion = nuevo; }
void CJugador::cambiar_vidas(int nuevo) { vidas = nuevo; }
void CJugador::cambiar_puntaje(int nuevo) { puntaje = nuevo; }
void CJugador::cambiar_dispMax(int nuevo) { disp_max = nuevo; }
void CJugador::cambiar_dispRea(int nuevo) { disp_rea = nuevo; }
void CJugador::cambiar_cantBasura(int nuevo) { cantBasura = nuevo; }
void CJugador::cambiar_desacControles(bool nuevo) { desact_controles = nuevo; }
void CJugador::cambiar_desacDibujo(bool nuevo) { desact_dibujo = nuevo; }
void CJugador::cambiar_desacPlataforma(bool nuevo) { desact_plataforma = nuevo; }
int CJugador::retornar_cantB() { return *cantBala; }
int CJugador::retornar_x() { return x; }
int CJugador::retornar_y() { return y; }
int CJugador::retornar_dx() { return dx; }
int CJugador::retornar_dy() { return dy; }
int CJugador::retornar_w() { return ancho; }
int CJugador::retornar_h() { return alto; }
int CJugador::retornar_indiceX() { return ind_x; }
int CJugador::retornar_indiceY() { return ind_y; }
bool CJugador::retornar_desacControles() { return desact_controles; }
Direcciones CJugador::retornar_ultimaDireccion() { return ultimaDireccion; }
int CJugador::retonar_vidas() { return vidas; }
int CJugador::retornar_puntaje() { return puntaje; }
int CJugador::retornar_dispMax() { return disp_max; }
int CJugador::retornar_dispRea() { return disp_rea; }
int CJugador::retornar_cantBasura() { return cantBasura; }
CBala* CJugador::retornar_bala(int indice) { return arrBala[indice]; }
CPlataforma* CJugador::retornar_plataforma() { return plataformJug; }
void CJugador::dibujar_personaje(BufferedGraphics^ buffer, Bitmap^ bmp, int MAX_W, int MAX_H){
	Rectangle porcionAUsar = Rectangle(ind_x * ancho, ind_y * alto, ancho, alto);
	Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 0.8, alto * 0.8);
	buffer->Graphics->DrawImage(bmp, aumentoPersonaje, porcionAUsar, GraphicsUnit::Pixel);
	if (x + dx > -10 && x + dx + ancho * 0.8 <= MAX_W)
		x += dx;
	if (y + dy > MAX_H - (MAX_H / 2.6) && y + dy + alto * 0.7 <= MAX_H)
		y += dy;
}
void CJugador::mover_personaje(BufferedGraphics^ buffer, Bitmap^ bmp, int MAX_W, int MAX_H, Bitmap^ bmpBala, Bitmap^ bmpPlataforma){
	if (desact_controles == false) {
		switch (direccion)
		{
		case arriba:
			ind_y = 2;
			if (ind_x >= 0 && ind_x < 2)
				ind_x++;
			else
				ind_x = 0;
			dx = 0;
			dy = -avance;
			ultimaDireccion = arriba;
			break;
		case abajo:
			ind_y = 0;
			if (ind_x >= 0 && ind_x < 2)
				ind_x++;
			else
				ind_x = 0;
			dx = 0;
			dy = avance;
			ultimaDireccion = abajo;
			break;
		case izquierda:
			ind_y = 3;
			if (ind_x >= 0 && ind_x < 2)
				ind_x++;
			else
				ind_x = 0;
			dx = -avance;
			dy = 0;
			ultimaDireccion = izquierda;
			break;
		case derecha:
			ind_y = 1;
			if (ind_x >= 0 && ind_x < 2)
				ind_x++;
			else
				ind_x = 0;
			dx = avance;
			dy = 0;
			ultimaDireccion = derecha;
			break;
		case ninguno:
			dx = 0;
			dy = 0;
			switch (ultimaDireccion) {
			case arriba:
				ind_x = 0;
				ind_y = 2;
				break;
			case abajo:
				ind_x = 0;
				ind_y = 0;
				break;
			case izquierda:
				ind_x = 0;
				ind_y = 3;
				break;
			case derecha:
				ind_x = 0;
				ind_y = 1;
				break;
			}
		}
	}
	if (desact_plataforma == false)
		plataformJug->dibujar_plataforma(buffer, bmpPlataforma, x, y);
	if (desact_dibujo == false)
		dibujar_personaje(buffer, bmp, MAX_W, MAX_H);
}
void CJugador::disparar(categoria _categoria) {
	if (*cantBala < max_balas) {
		CBala** copia = new CBala * [*cantBala + 1];
		for (int i = 0; i < *cantBala; i++)
			copia[i] = arrBala[i];
		copia[*cantBala] = new CBala();
		copia[*cantBala]->cambiar_categoria(_categoria);
		if (ultimaDireccion == arriba)
		{
			copia[*cantBala]->cambiar_dy(-15);
			copia[*cantBala]->cambiar_y(y);
			copia[*cantBala]->cambiar_x(x + ancho / 2);
		}
		else if (ultimaDireccion == Direcciones::abajo)
		{
			copia[*cantBala]->cambiar_dy(15);
			copia[*cantBala]->cambiar_y(y + alto / 2);
			copia[*cantBala]->cambiar_x(x + ancho / 2);
		}
		else if (ultimaDireccion == Direcciones::izquierda)
		{
			copia[*cantBala]->cambiar_dx(-15);
			copia[*cantBala]->cambiar_y(y + (alto /4));
			copia[*cantBala]->cambiar_x(x - (ancho / 2));
		}
		else if (ultimaDireccion == Direcciones::derecha)
		{
			copia[*cantBala]->cambiar_dx(15);
			copia[*cantBala]->cambiar_y(y + (alto /4));
			copia[*cantBala]->cambiar_x(x + (ancho / 2));
		}
		*cantBala = *cantBala + 1;
		arrBala = copia;
	}
}
void CJugador::mover_balas(BufferedGraphics^ buffer, Bitmap^ bmpBala) {
	int cantidad = 0;
	for (int i = 0; i < *cantBala; i++)
		cantidad += arrBala[i]->retornar_eliminar() ? 1 : 0;

	CBala** copia = new CBala * [*cantBala - cantidad];
	int j = 0;
	for (int i = 0; i < *cantBala; i++)
	{
		if (!arrBala[i]->retornar_eliminar())
		{
			copia[j] = arrBala[i];
			j++;
		}
	}
	*cantBala = *cantBala - cantidad;
	arrBala = copia;

	for (int i = 0; i < *cantBala; i++) {
		arrBala[i]->mover(buffer, bmpBala);
	}	
}
void CJugador::mostrar_vidas(BufferedGraphics^ buffer, Bitmap^ bmp_Vidas, int MAX_W, int MAX_H) {
	int alto_vida = bmp_Vidas->Height;
	int ancho_vida = bmp_Vidas->Width / 6;
	if (vidas <= 0)vidas = 0;
	Rectangle porcionAUsar = Rectangle(ancho_vida * (MAX_vida -  vidas), 0, ancho_vida, alto_vida);
	Rectangle aumentoTVida = Rectangle(40, 40, ancho_vida * 1, alto_vida * 1);
	buffer->Graphics->DrawImage(bmp_Vidas, aumentoTVida, porcionAUsar, GraphicsUnit::Pixel);

	System::String^ cant = System::String::Format("{0}", cantBasura);
	Font^ font = gcnew Font("Arial Black", 20);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::White);
	StringFormat^ formato = gcnew StringFormat();
	formato->FormatFlags = StringFormatFlags::DirectionRightToLeft;

	buffer->Graphics->DrawString(cant, font, solidBrush, 200, 115, formato);

	if (cantBasura >= 5 && (vidas > 0 && vidas < 5)) {
		cantBasura = cantBasura - 5;
		vidas = vidas + 1;
	}
}