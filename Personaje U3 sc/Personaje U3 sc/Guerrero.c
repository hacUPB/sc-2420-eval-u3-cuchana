#include "Guerrero.h"
#include <stdlib.h>
#include <string.h>

static void mostrar_estado_impl(const Personaje* this) {
    Guerrero* guerrero = (Guerrero*)this;
    printf("Guerrero: %s | Vida: %d | Nivel: %d | Fuerza: %d | Arma: %s\n", this->nombre, this->vida, this->nivel, guerrero->fuerza, this->arma->nombre);
}
static void atacar_impl(const Personaje* this) {
    Guerrero* guerrero = (Guerrero*)this;
    printf("%s ataca con %s causando %d de daño.\n", this->nombre, this->arma->nombre, this->arma->daño);
}

Guerrero* Guerrero_crear(const char* nombre, int vida, int nivel, int fuerza, Arma* arma) {
    Guerrero* nuevo_guerrero = (Guerrero*)malloc(sizeof(Guerrero));
    if (!nuevo_guerrero) return NULL;
    nuevo_guerrero->base.nombre = (char*)malloc(strlen(nombre) + 1);
    strcpy_s(nuevo_guerrero->base.nombre, strlen(nombre) + 1, nombre);
    nuevo_guerrero->base.vida = vida;
    nuevo_guerrero->base.nivel = nivel;
    nuevo_guerrero->base.arma = arma;
    nuevo_guerrero->base.mostrar_estado = mostrar_estado_impl;
    nuevo_guerrero->base.atacar = atacar_impl;
    nuevo_guerrero->fuerza = fuerza;
    return nuevo_guerrero;
}

void Guerrero_destruir(Guerrero* this) {
    if (this) {
        free(this->base.nombre);
        free(this);
    }
}
