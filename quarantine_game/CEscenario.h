#pragma once
using namespace System::Drawing;
enum Mundo {responsable, irresponsable};
class CEscenario
{
private:
	Mundo mundo;
	int alto, ancho;
	int ind_x, ind_y;
public:
	CEscenario();
	~CEscenario();
	void cambiar_mundo(Mundo nuevo);
	void cambiar_alto(int nuevo);
	void cambiar_ancho(int nuevo);
	void cambiar_indiceX(int nuevo);
	void cambiar_indiceY(int nuevo);
	Mundo retornar_mundo();
	int retornar_alto();
	int retonnar_ancho();
	int retonar_indiceX();
	int retonar_indiceY();
	void mostrar_escenario(BufferedGraphics^ buffer, Bitmap^ mundoResponsable, Bitmap^ mundoIrresponsable);
};

