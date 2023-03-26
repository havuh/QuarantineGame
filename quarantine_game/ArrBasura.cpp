#include "ArrBasura.h"

ArrBasura::ArrBasura(int cant_MAX) {
	init(cant_MAX);
}
ArrBasura::~ArrBasura() {
	for (int i = 0; i < *tmn; i++)
		delete arreglo[i];
	delete tmn;
}
void ArrBasura::init(int cant_MAX) {
	tmn = new int;
	*tmn = 0;
	cantMax = cant_MAX;
	iniciar = false;
}
void ArrBasura::insertar_basura(BufferedGraphics^ buffer, Bitmap^ bmpBasura) {
	if (*tmn < cantMax && iniciar == false) {
		if (*tmn + 1 == cantMax) iniciar = true;
		int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
		int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
		Basura** copia = new Basura * [*tmn + 1];
		for (int i = 0; i < *tmn; i++)
			copia[i] = arreglo[i];
		copia[*tmn] = new Basura();
		copia[*tmn]->cambiar_w(bmpBasura->Width / 8);
		copia[*tmn]->cambiar_h(bmpBasura->Height / 1);
		copia[*tmn]->cambiar_x(1 + rand() % (MAX_W - int((bmpBasura->Width / 8) * 0.3)));
		copia[*tmn]->cambiar_y((MAX_H + 50 - (MAX_H / 4)) + rand() % 130);
		copia[*tmn]->cambiar_indX(1 + rand() % 8);
		copia[*tmn]->cambiar_indY(0);

		*tmn = *tmn + 1;
		arreglo = copia;
	}
}
void ArrBasura::dibujar_todos(BufferedGraphics^ buffer, Bitmap^ bmpBasura) {
	for (int i = 0; i < *tmn; i++) {
		arreglo[i]->dibujar_basura(buffer, bmpBasura);
	}
}
void ArrBasura::eliminar_basura() {
	int cantidad = 0;
	for (int i = 0; i < *tmn; i++) {
		if (arreglo[i]->retornar_eliminarBasura() == true) {
			cantidad++;
		}
	}
	if (cantidad > 0) {
		Basura** copia = new Basura * [*tmn - cantidad];
		int j = 0;
		for (int i = 0; i < *tmn; i++) {
			if (!arreglo[i]->retornar_eliminarBasura()) {
				copia[j] = arreglo[i];
				j++;
			}
		}
		*tmn = *tmn - cantidad;
		arreglo = copia;
	}
}
int ArrBasura::retornar_tmn() { return *tmn; }
Basura* ArrBasura::retornar_basura(int indice) { return arreglo[indice]; }