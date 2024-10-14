#ifndef MAGO_H
#define MAGO_H

#include "Personaje.h"

typedef struct Mago {
    Personaje base;
    int mana;

} Mago;

Mago* Mago_crear(const char* nombre, int vida, int nivel, int mana, Arma* arma);
void Mago_destruir(Mago* this);

#endif // MAGO_H


