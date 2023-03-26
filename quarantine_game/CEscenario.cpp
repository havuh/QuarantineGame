#include "CEscenario.h"

CEscenario::CEscenario(){ 
	mundo = responsable;
	ancho = 1920;
	alto = 1080;
	ind_x = 0;
	ind_y = 0;
}
CEscenario::~CEscenario(){ }
void CEscenario::cambiar_mundo(Mundo nuevo) { mundo = nuevo; }
void CEscenario::cambiar_alto(int nuevo) { alto = nuevo; }
void CEscenario::cambiar_ancho(int nuevo) { ancho = nuevo; }
void CEscenario::cambiar_indiceX(int nuevo) { ind_x = nuevo; }
void CEscenario::cambiar_indiceY(int nuevo) { ind_y = nuevo; }
Mundo CEscenario::retornar_mundo() { return mundo; }
int CEscenario::retornar_alto() { return alto; }
int CEscenario::retonnar_ancho() { return ancho; }
int CEscenario::retonar_indiceX() { return ind_x; }
int CEscenario::retonar_indiceY() { return ind_y; }
void CEscenario::mostrar_escenario(BufferedGraphics^ buffer, Bitmap^ mundoResponsable, Bitmap^ mundoIrresponsable) {
	Rectangle porcionAUsar = Rectangle(ind_x * ancho, ind_y * alto, ancho, alto);
	Rectangle aumentoMapa = Rectangle(0, 0, ancho * 0.8, alto * 0.8);
	if (mundo == responsable ) {
		buffer->Graphics->DrawImage(mundoResponsable, aumentoMapa, porcionAUsar, GraphicsUnit::Pixel);
	}
	else if (mundo == irresponsable) {
		buffer->Graphics->DrawImage(mundoIrresponsable, aumentoMapa, porcionAUsar, GraphicsUnit::Pixel);
	}
}