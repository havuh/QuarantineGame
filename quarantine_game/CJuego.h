#pragma once
using namespace System::Drawing;
enum Resultado {ganar, perder, ningunoR};
#include "CJugador.h"
#include "CEscenario.h"
#include "ArrAdversarios.h"
#include "ArrBasura.h"
#include "CMensaje.h"
#include "CAmbulancia.h"
#include "CPolicia.h"
#include "CReloj.h"
#include "CLetreros.h"
class CJuego
{
private:
	Resultado result;
	int tiemp_seg;
	int tiemp_min;
	int tiemp_hor;
	int T_ANCHO;
	int T_ALTO;
	CJugador* objJug;
	CEscenario* objEsc;
	ArrAdversarios* objAdv;
	ArrBasura* objBasura;
	CMensaje* objMensaje;
	CAmbulancia* objAmbulancia;
	CPolicia* objPolicia;
	CReloj* objReloj;
	CLetreros* objLetreros;
	int dificultad;
	int tiempoDJuego;
	int enemEliminados;
public:
	CJuego(int _tAncho, int _tAlto, int _vidasJug, int _difJueg, int tiemDJuego);
	~CJuego();
	int retornar_enemEliminados();
	Resultado retornar_result();
	CJugador* retornar_objJugador();
	ArrBasura* retornar_objBasura();
	void cambiar_cambianTiempo(int seg, int min, int hor);
	void init(int _tAncho, int _tAlto, int _vidasJug, int _difJueg, int tiemDJuego);
	void DinamicaDelJuego(BufferedGraphics^ buffer, Bitmap^ bmpPersonaje, Bitmap^ mundoResponsable, Bitmap^ mundoIrresponsable, Bitmap^ bmpVidas, Bitmap^ bmpBala, int* timerMiliseg,
		Bitmap^ bmpAdversarios1, Bitmap^ bmpAdversarios2, Bitmap^ bmpBasura, Bitmap^ bmpMensaje, Bitmap^ bmpAmbulancia, Bitmap^ bmpPolicia, Bitmap^ bmpPlataforma, Bitmap^ bmpNivel
		, Bitmap^ bmpLetrero1, Bitmap^ bmpLetrero2);
	void mover_adversarios(BufferedGraphics^ buffer, Bitmap^ Adversario1, Bitmap^ Adversario2);
	void eliminando_adversarios(BufferedGraphics^ buffer, Bitmap^ Adversario1, Bitmap^ Adversario2);
	void dibujar_nivel(BufferedGraphics^ buffer, Bitmap^ bmpNivel);
	void dibujar_puntaje(BufferedGraphics^ buffer);
	void finDelJuego(BufferedGraphics^ buffer, Bitmap^ bmpLetrero1);
	void ganarJuego(BufferedGraphics^ buffer, Bitmap^ bmpLetrero1);
	void nextNivel(BufferedGraphics^ buffer, Bitmap^ bmpLetrero2);
	void reseteo_nivel1(BufferedGraphics^ buffer);
	void colision_JugadorBasura();
	void colision_BalajugadorAdversarios();
	void colision_JugadorAdversarios();
	void colision_BalajugadorBaladversario();
	void colision_BaladversarioJugador();
};

