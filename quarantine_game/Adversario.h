#pragma once
#include "NPC.h"
#include "CBala.h"
enum categoriaA { asintomatico, saludable };
class Adversario :
	public NPC
{
private:
	int vidas;
	categoriaA categ;
	Direcciones ultimaDireccion;
	int avance;
	bool recibio_pdisp;
	int ini_c, fin_c;
	int tipoEnem;
	int tipoMundo;
	bool eliminar;
	bool eliminando;
	int cambio;
	CBala** arregoB;
	int* tmnB;
	bool desacMovimiento;
public:
	Adversario();
	~Adversario();
	void cambiar_vidas(int nuevo);
	void cambiar_categorias(categoriaA nuevo);
	void cambiar_avance(int nuevo);
	void cambiar_recibio_disp(bool nuevo);
	void cambiar_tipoEnem(int nuevo);
	void cambiar_eliminar(bool nuevo);
	void cambiar_eliminando(bool nuevo);
	void cambiar_finC(int nuevo);
	void cambiar_desacMovimiento(bool nuevo);
	void cambiar_tipoDMundo(int nuevo);
	bool retornar_eliminando();
	int retornar_vidas();
	categoriaA retornar_categoria();
	Direcciones retornar_ultimaDireccion();
	int retornar_avance();
	bool retornar_recibio_disp();
	int retornar_tipoEnem();
	bool retornar_eliminar();
	int retornar_finC();
	void mover_adversario(BufferedGraphics^ buffer, Bitmap^ bmp, Bitmap^ bmp2, Direcciones direccion);
	void dibujar_adversario(BufferedGraphics^ buffer, Bitmap^ bmp);
};

