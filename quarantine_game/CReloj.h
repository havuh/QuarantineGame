#pragma once
using namespace System::Drawing;
class CReloj
{
private:
	int seg, min, hor;
public:
	CReloj();
	~CReloj();
	int retornar_seg();
	int retornar_min();
	int retornar_hor();
	bool seTerminoJuego(int JuegMin, int JuegSeg);
	void iniciar_reloj(int segundos, int minutos, int horas);
	void dibujar_reloj(BufferedGraphics^ buffer, int _tiempo);
};

