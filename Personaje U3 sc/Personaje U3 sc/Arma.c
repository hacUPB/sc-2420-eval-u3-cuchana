#include "Arma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void mostrar_info_impl(const Arma* this) {
    printf("Arma: %s | Daño: %d | Alcance: %d\n", this->nombre, this->daño, this->alcance);
}

Arma* Arma_crear(const char* nombre, int daño, int alcance) {
    Arma* nueva_arma = (Arma*)malloc(sizeof(Arma));
    if (!nueva_arma) return NULL;
    nueva_arma->nombre = (char*)malloc(strlen(nombre) + 1);
    strcpy_s(nueva_arma->nombre, strlen(nombre) + 1, nombre);
    nueva_arma->daño = daño;
    nueva_arma->alcance = alcance;
    nueva_arma->mostrar_info = mostrar_info_impl;
    return nueva_arma;
}

void Arma_destruir(Arma* this) {
    if (this) {
        free(this->nombre);
        free(this);
    }
}
