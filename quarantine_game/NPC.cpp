#include "NPC.h"

NPC::NPC(){ }
NPC::~NPC(){ }
void NPC::cambiar_x(int nuevo) { x = nuevo; }
void NPC::cambiar_y(int nuevo) { y = nuevo; }
void NPC::cambiar_dx(int nuevo) { dx = nuevo; }
void NPC::cambiar_dy(int nuevo) { dy = nuevo; }
void NPC::cambiar_w(int nuevo) { w = nuevo; }
void NPC::cambiar_h(int nuevo) { h = nuevo; }
void NPC::cambiar_indX(int nuevo) { ind_x = nuevo; }
void NPC::cambiar_indY(int nuevo) { ind_y = nuevo; }
int NPC::retornar_x() { return x; }
int NPC::retornar_y() { return y; }
int NPC::retornar_dx() { return dx; }
int NPC::retornar_dy() { return dy; }
int NPC::retornar_w() { return w; }
int NPC::retornar_h() { return h; }
int NPC::retornar_indX() { return ind_x; }
int NPC::retornar_indY() { return ind_y; }