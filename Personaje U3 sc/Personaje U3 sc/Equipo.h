#ifndef EQUIPO_H
#define EQUIPO_H

#include "Personaje.h"

typedef struct Equipo {
    Personaje** personajes;
    int cantidad_personajes;
} Equipo;

Equipo* Equipo_crear();
void Equipo_agregar_personaje(Equipo* this, Personaje* personaje);
void Equipo_mostrar_estado(const Equipo* this);
void Equipo_destruir(Equipo* this);

#endif // EQUIPO_H
