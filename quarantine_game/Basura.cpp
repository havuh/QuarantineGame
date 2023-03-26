#include "Basura.h"

Basura::Basura() {
	dx = dy = 0;
	eliminar_basura = false;
}
Basura::~Basura(){}
void Basura::cambiar_eliminarBasura(bool nuevo) { eliminar_basura = nuevo; }
bool Basura::retornar_eliminarBasura() { return eliminar_basura; }
void Basura::dibujar_basura(BufferedGraphics^ buffer, Bitmap^ bmpBasura) {
	Rectangle porcionAUsar = Rectangle(ind_x * w, ind_y * h, w, h);
	Rectangle aumentoPersonaje = Rectangle(x, y, w * 0.3, h * 0.3);
	buffer->Graphics->DrawImage(bmpBasura, aumentoPersonaje, porcionAUsar, GraphicsUnit::Pixel);
}