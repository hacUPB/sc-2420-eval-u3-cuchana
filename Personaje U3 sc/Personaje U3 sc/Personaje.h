#ifndef PERSONAJE_H
#define PERSONAJE_H

#include "Arma.h"

typedef struct Personaje {
    char* nombre;
    int vida;
    int nivel;
    Arma* arma;
    void (*mostrar_estado)(const struct Personaje* this);
    void (*atacar)(const struct Personaje* this);
} Personaje;

Personaje* Personaje_crear(const char* nombre, int vida, int nivel, Arma* arma);
void Personaje_destruir(Personaje* this);

#endif // PERSONAJE_H

