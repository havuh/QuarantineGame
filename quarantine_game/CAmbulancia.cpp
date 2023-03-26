#include "CAmbulancia.h"

CAmbulancia::CAmbulancia() {
	cantidad = 0;
	dx = 2;
	dy = 0;
	ind_x = 1;
	ind_y = 0;
	x = -500;
}
void CAmbulancia::cambiar_cantidad(int nuevo) { cantidad = nuevo; }
int CAmbulancia::retornar_cantidad() { return cantidad; }
CAmbulancia::~CAmbulancia(){}
void CAmbulancia::dibujar_ambulancia(BufferedGraphics^ buffer, Bitmap^ bmpAmbulancia) {
	y = buffer->Graphics->VisibleClipBounds.Height - (buffer->Graphics->VisibleClipBounds.Height / 2 - 60);
	w = bmpAmbulancia->Width / 2;
	h = bmpAmbulancia->Height;
	Rectangle porcioAUsar = Rectangle(ind_x * w, ind_y * h, w, h);
	Rectangle aumentoBMP = Rectangle(x, y, w*0.8, h * 0.8);
	buffer->Graphics->DrawImage(bmpAmbulancia, aumentoBMP, porcioAUsar, GraphicsUnit::Pixel);
}
void CAmbulancia::mover_ambulancia(BufferedGraphics^ buffer, Bitmap^ bmpAmbulancia) {
	if (x <= - 120) {
		x = x + dx;
	}
	dibujar_ambulancia(buffer, bmpAmbulancia);
}