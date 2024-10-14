#include "Equipo.h"
#include <stdio.h>
#include <stdlib.h>

Equipo* Equipo_crear() {
    Equipo* nuevo_equipo = (Equipo*)malloc(sizeof(Equipo));
    if (!nuevo_equipo) return NULL;
    nuevo_equipo->personajes = NULL;
    nuevo_equipo->cantidad_personajes = 0;
    return nuevo_equipo;
}

void Equipo_agregar_personaje(Equipo* this, Personaje* personaje) {
    Personaje** nuevo_array = realloc(this->personajes, sizeof(Personaje*) * (this->cantidad_personajes + 1));
    if (nuevo_array) {
        this->personajes = nuevo_array;
        this->personajes[this->cantidad_personajes++] = personaje;
    }
}

void Equipo_mostrar_estado(const Equipo* this) {
    printf("Estado del equipo:\n");
    for (int i = 0; i < this->cantidad_personajes; ++i) {
        this->personajes[i]->mostrar_estado(this->personajes[i]);
    }
}

void Equipo_destruir(Equipo* this) {
    if (this) {
        free(this->personajes); // Solo liberar el array de punteros
        free(this);
    }
}
