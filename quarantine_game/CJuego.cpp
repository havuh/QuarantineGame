#include "CJuego.h"

CJuego::CJuego(int _tAncho, int _tAlto, int _vidasJug, int _difJueg, int _tiemDJuego){
	init(_tAncho, _tAlto, _vidasJug, _difJueg, _tiemDJuego);
}
CJuego::~CJuego(){ 
	delete objJug;
	delete objEsc;
	delete objAdv;
	delete objMensaje;
	delete objBasura;
	delete objAmbulancia;
	delete objPolicia;
	delete objReloj;
	delete objLetreros;
}
CJugador* CJuego::retornar_objJugador() { return objJug; }
ArrBasura* CJuego::retornar_objBasura() { return objBasura; }
Resultado CJuego::retornar_result() { return result; }
void CJuego::cambiar_cambianTiempo(int seg, int min, int hor) { tiemp_seg = seg; tiemp_min = min; tiemp_hor = hor; }
void CJuego::init(int _tAncho, int _tAlto, int _vidasJug, int _difJueg, int _tiemDJuego){
	T_ANCHO = _tAncho;
	T_ALTO = _tAlto;
	dificultad = _difJueg;
	tiempoDJuego = _tiemDJuego;
	enemEliminados = 0;
	result = Resultado::ningunoR;
	objJug = new CJugador(_vidasJug, 10, T_ALTO - 250);
	objEsc = new CEscenario();
	objAdv = new ArrAdversarios();
	objMensaje = new CMensaje();
	objBasura = new ArrBasura(3 + rand() % 5);
	objAmbulancia = new CAmbulancia();
	objPolicia = new CPolicia();
	objReloj = new CReloj();
	objLetreros = new CLetreros();
}
void CJuego::DinamicaDelJuego(BufferedGraphics^ buffer, Bitmap^ bmpPersonaje, Bitmap^ mundoResponsable, Bitmap^
	mundoIrresponsable, Bitmap^ bmpVidas, Bitmap^ bmpBala, int* timerMiliseg, Bitmap^ bmpAdversarios1, Bitmap^ bmpAdversarios2, Bitmap^ bmpBasura,
	Bitmap^ bmpMensaje, Bitmap^ bmpAmbulancia, Bitmap^ bmpPolica, Bitmap^ bmpPlataforma, Bitmap^ bmpNivel, Bitmap^ bmpLetrero1, Bitmap^ bmpLetrero2){
	objReloj->iniciar_reloj(tiemp_seg, tiemp_min, tiemp_hor);
	objBasura->insertar_basura(buffer, bmpBasura);
	objEsc->mostrar_escenario(buffer, mundoResponsable, mundoIrresponsable);
	dibujar_puntaje(buffer);
	objBasura->dibujar_todos(buffer, bmpBasura);
	objAmbulancia->mover_ambulancia(buffer, bmpAmbulancia);
	objPolicia->mover_policia(buffer, bmpPolica);
	int nRandom = 1 + rand() % 5;
	categoriaA cat;
	if (nRandom % 2 == 0) {
		cat = asintomatico;
	}
	else {
		cat = saludable;
	}
	if (objEsc->retornar_mundo() == Mundo::responsable)
		objAdv->insertar_adversarios(cat, 1, 1, buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height, tiemp_seg);
	else if (objEsc->retornar_mundo() == Mundo::irresponsable)
		objAdv->insertar_adversarios(cat, 1, 1, buffer->Graphics->VisibleClipBounds.Width, buffer->Graphics->VisibleClipBounds.Height, tiemp_seg);
	objJug->mover_balas(buffer, bmpBala);
	mover_adversarios(buffer, bmpAdversarios1, bmpAdversarios2);
	if (dificultad == 2)
		objAdv->disparar(objJug->retornar_x(), tiemp_seg);
	objAdv->mover_balas(buffer, bmpBala);
	objJug->mover_personaje(buffer, bmpPersonaje, T_ANCHO, T_ALTO, bmpBala, bmpPlataforma);
	objMensaje->dibujar_mensaje(buffer, bmpMensaje, objJug->retornar_x(), objJug->retornar_y());
	objJug->mostrar_vidas(buffer, bmpVidas, T_ANCHO, T_ALTO);
	colision_JugadorBasura();
	colision_BalajugadorAdversarios();
	colision_JugadorAdversarios();
	colision_BalajugadorBaladversario();
	colision_BaladversarioJugador();
	dibujar_nivel(buffer, bmpNivel);
	objReloj->dibujar_reloj(buffer, tiempoDJuego);
	finDelJuego(buffer, bmpLetrero1);
	nextNivel(buffer, bmpLetrero2);
	ganarJuego(buffer, bmpLetrero1);
}
int CJuego::retornar_enemEliminados() { return enemEliminados; }
void CJuego::mover_adversarios(BufferedGraphics^ buffer, Bitmap^ Adversario1, Bitmap^ Adversario2) {
	for (int i = 0; i < objAdv->retornar_tmn(); i++) {
		if (objAdv->retornar_adversario(i)->retornar_eliminando() == false) {
			if (objAdv->retornar_adversario(i)->retornar_x() > objJug->retornar_x() + 30 * (i + 2)) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::izquierda);
			}
			else if (objAdv->retornar_adversario(i)->retornar_x() < objJug->retornar_x() - 30 * (i + 2)) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::derecha);
			}
			else if (objAdv->retornar_adversario(i)->retornar_y() < objJug->retornar_y() - 12) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::abajo);
			}
			else if (objAdv->retornar_adversario(i)->retornar_y() > objJug->retornar_y() + 12) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::arriba);
			}
			else {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::ninguno);
			}
		}
	}
	eliminando_adversarios(buffer, Adversario1, Adversario2);
}
void CJuego::dibujar_nivel(BufferedGraphics^ buffer, Bitmap^ bmpNivel) {
	int h = bmpNivel->Height / 4;
	int w = bmpNivel->Width;
	int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
	int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
	int ind_y;
	if (objEsc->retornar_mundo() == Mundo::responsable)
		ind_y = 0;
	else if (objEsc->retornar_mundo() == Mundo::irresponsable)
		ind_y = 1;
	Rectangle porcionAUsar = Rectangle(0, h*ind_y, w, h);
	Rectangle aumentoBMP = Rectangle(MAX_W - w*0.5 + 10, MAX_H - h*0.5 - 10, w * 0.5, h * 0.5);
	buffer->Graphics->DrawImage(bmpNivel, aumentoBMP, porcionAUsar, GraphicsUnit::Pixel);
}
void CJuego::dibujar_puntaje(BufferedGraphics^ buffer) {
	int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
	int MAX_H = buffer->Graphics->VisibleClipBounds.Height;

	System::String^ texto = "S C O R E";
	System::String^ puntaje;
	if (objJug->retornar_puntaje() < 10)
		puntaje = System::String::Format("000{0}", objJug->retornar_puntaje());
	else if (objJug->retornar_puntaje() >= 10 && objJug->retornar_puntaje() < 100)
		puntaje = System::String::Format("00{0}", objJug->retornar_puntaje());
	else if (objJug->retornar_puntaje() >= 100 && objJug->retornar_puntaje() < 1000)
		puntaje = System::String::Format("0{0}", objJug->retornar_puntaje());
	else if (objJug->retornar_puntaje() >= 1000 && objJug->retornar_puntaje() < 10000)
		puntaje = System::String::Format("{0}", objJug->retornar_puntaje());
	else if (objJug->retornar_puntaje() >= 10000)
		puntaje = System::String::Format("9999");
	Font^ font = gcnew Font("Arial Black", 20);
	Font^ font2 = gcnew Font("Arial Black", 30);
	SolidBrush^ solidBrush = gcnew SolidBrush(Color::Red);
	SolidBrush^ solidBrush2 = gcnew SolidBrush(Color::White);
	SolidBrush^ solidBrush3 = gcnew SolidBrush(Color::Black);
	StringFormat^ formato = gcnew StringFormat();
	formato->FormatFlags = StringFormatFlags::DirectionRightToLeft;
	Rectangle rectangulo = Rectangle(MAX_W - 200, 30, 200, 100);
	float x = MAX_W - 15, y = 45;

	buffer->Graphics->FillRectangle(solidBrush3, rectangulo);
	buffer->Graphics->DrawRectangle(Pens::Aqua, MAX_W - 195, 35, 200, 90);
	buffer->Graphics->DrawString(texto, font, solidBrush, x, y, formato);
	buffer->Graphics->DrawString(puntaje, font2, solidBrush2, x , y + 20, formato);
}
void CJuego::finDelJuego(BufferedGraphics^ buffer, Bitmap^ bmpLetrero1) {
	if (objJug->retonar_vidas() <= 0) {
		objJug->cambiar_desacControles(true);
		result = Resultado::perder;
		objLetreros->mover_letreroYouLose(buffer, bmpLetrero1);
		objJug->cambiar_desacPlataforma(true);
		objJug->cambiar_desacDibujo(true);
		objMensaje->cambiar_desacMensaje(true);
		for (int i = 0; i < objAdv->retornar_tmn(); i++) {
			objAdv->retornar_adversario(i)->cambiar_desacMovimiento(true);
		}
	}
	else if (objReloj->retornar_min() >= tiempoDJuego) {
		objJug->cambiar_desacControles(true);
		result = Resultado::perder;
		objJug->cambiar_desacPlataforma(true);
		objLetreros->mover_letreroYouLose(buffer, bmpLetrero1);
		objMensaje->cambiar_desacMensaje(true);
		for (int i = 0; i < objAdv->retornar_tmn(); i++) {
			objAdv->retornar_adversario(i)->cambiar_desacMovimiento(true);
		}
	}
}
void CJuego::ganarJuego(BufferedGraphics^ buffer, Bitmap^ bmpLetrero1) {
	if (objEsc->retornar_mundo() == Mundo::irresponsable && objAdv->retornar_tmn() <= 0  && (objAmbulancia->retornar_cantidad() + objPolicia->retornar_cantidad() > 10)) {
		result = Resultado::ganar;
		objLetreros->mover_letreroYouWin(buffer, bmpLetrero1);
	}
}
void CJuego::reseteo_nivel1(BufferedGraphics^ buffer) {
	int MAX_H = buffer->Graphics->VisibleClipBounds.Height;
	buffer->Graphics->Clear(Color::Black);
	objEsc->cambiar_mundo(Mundo::irresponsable);
	objAdv->cambiar_cantMax(8 + rand() % 2);
	objAdv->cambiar_tiempPrueba(tiemp_seg + 2);
	objAdv->cambiar_generado2(true);
	objAdv->cambiar_ingresoB(false);
	objJug->cambiar_x(10);
	objJug->cambiar_y(MAX_H - 250);
	objBasura->init(5 + rand() % 10);
	objAmbulancia->cambiar_x(-500);
	int cantEnem1 = objPolicia->retornar_cantidad();
	objPolicia->init();
	objPolicia->cambiar_cantidad(cantEnem1);
}
void CJuego::nextNivel(BufferedGraphics^ buffer, Bitmap^ bmpLetrero2) {
	if (objAdv->retornar_tmn() == 0 && objAdv->retornar_generado() == true && objEsc->retornar_mundo() == Mundo::responsable) {
		objLetreros->mover_letreroNext(buffer, bmpLetrero2);
		int MAX_W = buffer->Graphics->VisibleClipBounds.Width;
		if (objJug->retornar_x() >= MAX_W - 150) {
			reseteo_nivel1(buffer);
		}
	}
}
void CJuego::colision_JugadorBasura() {
	Rectangle jugador = Rectangle(objJug->retornar_x() + (objJug->retornar_w() * 0.5), objJug->retornar_y() + (objJug->retornar_h() * 0.5), (objJug->retornar_w() * 0.8) / 4, (objJug->retornar_h() * 0.8) / 4);
	for (int i = 0; i < objBasura->retornar_tmn(); i++) {
		Basura* basur = objBasura->retornar_basura(i);
		Rectangle basura = Rectangle(basur->retornar_x(), basur->retornar_y(), basur->retornar_w() * 0.3, basur->retornar_h() * 0.3);
		if (jugador.IntersectsWith(basura)) {
			basur->cambiar_eliminarBasura(true);
			objJug->cambiar_cantBasura(objJug->retornar_cantBasura() + 1);
		}
	}
	objBasura->eliminar_basura();
}
void CJuego::colision_BalajugadorAdversarios() {
	for (int i = 0; i < objJug->retornar_cantB(); i++) {
		CBala* bala = objJug->retornar_bala(i);
		Rectangle disparo = Rectangle(bala->retornar_x(), bala->retornar_y(), bala->retornar_w()*0.7, bala->retornar_h()*0.7);
		for (int j = 0; j < objAdv->retornar_tmn(); j++) {
			Adversario* adver = objAdv->retornar_adversario(j);
			Rectangle adversario = Rectangle(adver->retornar_x(), adver->retornar_y() + (adver->retornar_h() * 0.7 / 4), adver->retornar_w()*0.7, (adver->retornar_h()*0.7) / 5);
			if (adversario.IntersectsWith(disparo) && adver->retornar_eliminando() == false) {
				if ((adver->retornar_categoria() == asintomatico && bala->retornar_categoria() == categ2) || 
					(adver->retornar_categoria() == saludable && bala->retornar_categoria() == categ1)) {
					objAdv->retornar_adversario(j)->cambiar_vidas(objAdv->retornar_adversario(j)->retornar_vidas() - 1);
					if (adver->retornar_vidas() >= 1) {
						objAdv->retornar_adversario(j)->cambiar_recibio_disp(true);
					}
					else if (adver->retornar_vidas() <= 1) {
						objAdv->retornar_adversario(j)->cambiar_eliminando(true);
					}
					objJug->retornar_bala(i)->cambiar_eliminar(true); 
					objMensaje->generar_mensaje(objJug->retornar_x(), objJug->retornar_y());
					objMensaje->cambiar_seGenero(true);
				}
				else {
					objJug->retornar_bala(i)->cambiar_eliminar(true);
				}
				
			}
		}
	}
	objAdv->eliminar_adversarios();
}
void CJuego::eliminando_adversarios(BufferedGraphics^ buffer, Bitmap^ Adversario1, Bitmap^ Adversario2) {
	for (int i = 0; i < objAdv->retornar_tmn(); i++) {
		if (objAdv->retornar_adversario(i)->retornar_categoria() == asintomatico && objAdv->retornar_adversario(i)->retornar_eliminando() == true) {
			if (objAdv->retornar_adversario(i)->retornar_x() > objAmbulancia->retornar_x() + (objAmbulancia->retornar_w()*0.8) + 50) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::izquierda);
			}
			else if (objAdv->retornar_adversario(i)->retornar_x() < objAmbulancia->retornar_x() + (objAmbulancia->retornar_w() * 0.8) - 50) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::derecha);
			}
			else if (objAdv->retornar_adversario(i)->retornar_y() > objAmbulancia->retornar_y() + (objAmbulancia->retornar_h() * 0.3)) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::arriba);
			}
			else if (objAdv->retornar_adversario(i)->retornar_y() < objAmbulancia->retornar_y() + (objAmbulancia->retornar_h() * 0.2)) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::abajo);
			}
			else {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::ninguno);
				objAdv->retornar_adversario(i)->cambiar_eliminar(true);
				enemEliminados++;
				objJug->cambiar_puntaje(objJug->retornar_puntaje() + 10);
				objAmbulancia->cambiar_cantidad(objAmbulancia->retornar_cantidad() + 1);
			}
		}
		else if (objAdv->retornar_adversario(i)->retornar_categoria() == saludable && objAdv->retornar_adversario(i)->retornar_eliminando() == true) {
			if (objAdv->retornar_adversario(i)->retornar_x() > objPolicia->retornar_x() + (objPolicia->retornar_w() * 0.8) + 50) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::izquierda);
			}
			else if (objAdv->retornar_adversario(i)->retornar_x() < objPolicia->retornar_x() + (objPolicia->retornar_w() * 0.8) - 50) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::derecha);
			}
			else if (objAdv->retornar_adversario(i)->retornar_y() > objPolicia->retornar_y() + (objAmbulancia->retornar_h() * 0.3)) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::arriba);
			}
			else if (objAdv->retornar_adversario(i)->retornar_y() < objPolicia->retornar_y() + (objAmbulancia->retornar_h() * 0.2)) {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::abajo);
			}
			else {
				objAdv->retornar_adversario(i)->mover_adversario(buffer, Adversario1, Adversario2, Direcciones::ninguno);
				objAdv->retornar_adversario(i)->cambiar_eliminar(true);
				enemEliminados++;
				objJug->cambiar_puntaje(objJug->retornar_puntaje() + 10);
				objPolicia->cambiar_cantidad(objPolicia->retornar_cantidad() + 1);
			}
		}	
	}
}
void CJuego::colision_JugadorAdversarios() {
	Rectangle jugador = Rectangle(objJug->retornar_plataforma()->retornar_x(),objJug->retornar_plataforma()->retornar_y(), 
		objJug->retornar_plataforma()->retornar_w()*0.7, objJug->retornar_plataforma()->retornar_h()*0.7);
	for (int i = 0; i < objAdv->retornar_tmn(); i++) {
		Adversario* adver = objAdv->retornar_adversario(i);
		Rectangle adversario = Rectangle(adver->retornar_x(), adver->retornar_y(), adver->retornar_w() * 0.6, adver->retornar_h()*0.6);
		if (jugador.IntersectsWith(adversario) && adver->retornar_eliminando() != true) {
			objJug->cambiar_vidas(objJug->retonar_vidas() - 1);
			adver->cambiar_eliminar(true);
		}
	}
}
void CJuego::colision_BalajugadorBaladversario() {
	for (int i = 0; i < objJug->retornar_cantB(); i++) {
		CBala* BalaJug = objJug->retornar_bala(i);
		Rectangle r1 = Rectangle(BalaJug->retornar_x(), BalaJug->retornar_y(), BalaJug->retornar_w() * 0.7, BalaJug->retornar_h() * 0.7);
			for (int j = 0; j < objAdv->retornar_cantB(); j++) {
				CBala* BalaAdv = objAdv->retornar_bala(j);
				Rectangle r2 = Rectangle(BalaAdv->retornar_x(), BalaAdv->retornar_y(), BalaAdv->retornar_w() * 0.7, BalaAdv->retornar_h() * 0.7);
				if (r1.IntersectsWith(r2)) {
					objJug->retornar_bala(i)->cambiar_eliminar(true);
					objAdv->retornar_bala(j)->cambiar_eliminar(true);
				}
			}
	}
	objAdv->eliminar_balas();
}
void CJuego::colision_BaladversarioJugador() {
	Rectangle r1 = Rectangle(objJug->retornar_x(), objJug->retornar_y(), objJug->retornar_w()* 0.7, objJug->retornar_h() * 0.7);
	for (int i = 0; i < objAdv->retornar_cantB(); i++) {
		CBala* BalaAdv = objAdv->retornar_bala(i);
		Rectangle r2 = Rectangle(BalaAdv->retornar_x(), BalaAdv->retornar_y(), BalaAdv->retornar_w() * 0.7, BalaAdv->retornar_h() * 0.7);
		if (r2.IntersectsWith(r1)) {
			objJug->cambiar_vidas(objJug->retonar_vidas() - 1);
			objAdv->retornar_bala(i)->cambiar_eliminar(true);
		}
	}
}