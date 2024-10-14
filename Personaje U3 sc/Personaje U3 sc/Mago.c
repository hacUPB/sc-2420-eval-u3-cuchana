#include "Mago.h"
#include <stdlib.h>
#include <string.h>

static void mostrar_estado_impl(const Personaje* this) {
    Mago* mago = (Mago*)this;
    printf("Mago: %s | Vida: %d | Nivel: %d | Mana: %d | Arma: %s\n", this->nombre, this->vida, this->nivel, mago->mana, this->arma->nombre);
}
static void atacar_impl(const Personaje* this) {
    Mago* mago = (Mago*)this;
    printf("%s ataca con %s causando %d de daño.\n", this->nombre, this->arma->nombre, this->arma->daño);
}


Mago* Mago_crear(const char* nombre, int vida, int nivel, int mana, Arma* arma) {
    Mago* nuevo_mago = (Mago*)malloc(sizeof(Mago));
    if (!nuevo_mago) return NULL;
    nuevo_mago->base.nombre = (char*)malloc(strlen(nombre) + 1);
    strcpy_s(nuevo_mago->base.nombre, strlen(nombre) + 1, nombre);
    nuevo_mago->base.vida = vida;
    nuevo_mago->base.nivel = nivel;
    nuevo_mago->base.arma = arma;
    nuevo_mago->base.mostrar_estado = mostrar_estado_impl;
    nuevo_mago->base.atacar = atacar_impl;
    nuevo_mago->mana = mana;
    return nuevo_mago;
}

void Mago_destruir(Mago* this) {
    if (this) {
        free(this->base.nombre);
        free(this);
    }
}
