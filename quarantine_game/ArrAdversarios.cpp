#include "ArrAdversarios.h"

ArrAdversarios::ArrAdversarios() {
	maxBalas = 3;
	tiemPrueba = 7;
	tiemPrueba2 = 0;
	tmn = new int;
	*tmn = 0;
	cantB = new int;
	*cantB = 0;
	cant_max = 5 + rand() % 5;
	generado = false;
	generado2 = false;
	ingresoB = false;
}
ArrAdversarios::~ArrAdversarios() {
	for (int i = 0; i < *tmn; i++)
		delete arreglo[i];
	delete tmn;
}
CBala* ArrAdversarios::retornar_bala(int indice) { return arregloB[indice]; }
void ArrAdversarios::cambiar_cantB(int nuevo) { *cantB = nuevo; }
int ArrAdversarios::retornar_cantB() { return *cantB; }
int ArrAdversarios::retornar_maxBalas() { return maxBalas; }
void ArrAdversarios::cambiar_cantMax(int nuevo) { cant_max = nuevo; }
Adversario* ArrAdversarios::retornar_adversario(int indice) { return arreglo[indice]; }
void ArrAdversarios::cambiar_tiempPrueba(int nuevo) { tiemPrueba = nuevo; }
int ArrAdversarios::retornar_tmn() { return *tmn; }
void ArrAdversarios::cambiar_generado(bool nuevo) { generado = nuevo; }
bool ArrAdversarios::retornar_generado() { return generado; }
bool ArrAdversarios::retornar_generado2() { return generado2; }
void ArrAdversarios::cambiar_generado2(bool nuevo) { generado2 = nuevo; }
void ArrAdversarios::insertar_adversarios(categoriaA _categ, int _tipoEnem, int tipoMundo, int MAX_W, int MAX_H, int tiempSeg) {
	int numero = 1 + rand() % 30;
	if (tiempSeg > 5 && tiemPrueba == tiempSeg && (generado == false || generado2 == true)) { 
		int nRand = (MAX_W - 300) + rand() % MAX_W;
		int posx = 0;
		Adversario** copia = new Adversario * [*tmn + 1];
		for (int i = 0; i < *tmn; i++)
			copia[i] = arreglo[i];
		copia[*tmn] = new Adversario();
		copia[*tmn]->cambiar_categorias(_categ);
		if (nRand % 2 == 0)
			copia[*tmn]->cambiar_x(nRand + (50 * (*tmn + 2)));
		else copia[*tmn]->cambiar_x(-90 - (100 * (*tmn + 2)));
		copia[*tmn]->cambiar_y((MAX_H - 350) + rand() % 120);
		copia[*tmn]->cambiar_tipoDMundo(tipoMundo);
		if (tipoMundo == 1) {
			copia[*tmn]->cambiar_tipoEnem(1);
			copia[*tmn]->cambiar_avance(10);
		}
		else {
			copia[*tmn]->cambiar_tipoEnem(2);
			copia[*tmn]->cambiar_avance(15);
		}
		*tmn = *tmn + 1;
		arreglo = copia;
		if (tipoMundo == 1 && *tmn + 1 == cant_max) generado = true;
		if (tipoMundo == 2 && *tmn + 1 == cant_max) generado2 = false;
		tiemPrueba = tiemPrueba + 2;
	}
}
void ArrAdversarios::eliminar_adversarios() {
	int cantidad = 0;
	for (int i = 0; i < *tmn; i++) {
		if (arreglo[i]->retornar_eliminar()) {
			cantidad++;
		}
	}
	if (cantidad > 0) {
		Adversario** copia = new Adversario * [*tmn - cantidad];
		int j = 0;
		for (int i = 0; i < *tmn; i++) {
			if (!arreglo[i]->retornar_eliminar()) {
				copia[j] = arreglo[i]; j++;
			}
		}
		*tmn = *tmn - cantidad;
		arreglo = copia;
	}
}
void ArrAdversarios::disparar(int x_jug, int _seg) {
	if (*tmn > 1 && *cantB < maxBalas) {
		int enm_al = rand() % *tmn;
		if (arreglo[enm_al]->retornar_eliminando() == false && tiemPrueba2 == _seg && enm_al != antecesor) {
			CBala** copia = new CBala * [*cantB + 1];
			for (int i = 0; i < *cantB; i++)
				copia[i] = arregloB[i];
			copia[*cantB] = new CBala();
			copia[*cantB]->cambiar_x(arreglo[enm_al]->retornar_x() + 30);
			copia[*cantB]->cambiar_y(arreglo[enm_al]->retornar_y() + 50);
			if (arreglo[enm_al]->retornar_categoria() == categoriaA::asintomatico)
				copia[*cantB]->cambiar_categoria(categ3);
			else copia[*cantB]->cambiar_categoria(categ4);
			if (copia[*cantB]->retornar_x() < x_jug)
				copia[*cantB]->cambiar_dx(15);
			else if (copia[*cantB]->retornar_x() > x_jug)
				copia[*cantB]->cambiar_dx(-15);
			*cantB = *cantB + 1;
			arregloB = copia;
			ingresoB = true;
			tiemPrueba2 = _seg + 2;
			antecesor = enm_al;
		}
		else
			tiemPrueba2 = _seg;
	}
	if (ingresoB == false) tiemPrueba2 = _seg;
}
void ArrAdversarios::cambiar_ingresoB(bool nuevo) { ingresoB = nuevo; }
void ArrAdversarios::mover_balas(BufferedGraphics^ buffer, Bitmap^ bmpBala) {
	for (int i = 0; i < *cantB; i++) {
		arregloB[i]->mover(buffer, bmpBala);
	}
}
void ArrAdversarios::eliminar_balas() {
	int cantidad = 0;
	for (int i = 0; i < *cantB; i++) {
		if (arregloB[i]->retornar_eliminar() == true) {
			cantidad++;
		}
	}
	if (cantidad > 0) {
		CBala** copia = new CBala * [*cantB - cantidad];
		int j = 0;
		for (int i = 0; i < *cantB; i++) {
			if (arregloB[i]->retornar_eliminar() != true) {
				copia[j] = arregloB[i];
				j++;
			}
		}
		*cantB = *cantB - cantidad;
		arregloB = copia;
	}
}