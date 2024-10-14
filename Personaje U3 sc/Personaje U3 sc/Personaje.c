#include "Personaje.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void mostrar_estado_impl(const Personaje* this) {
    printf("Personaje: %s | Vida: %d | Nivel: %d | Arma: %s\n", this->nombre, this->vida, this->nivel, this->arma->nombre);
}

static void atacar_impl(const Personaje* this) {
    printf("%s ataca con %s causando %d de daño.\n", this->nombre, this->arma->nombre, this->arma->daño);
}


Personaje* Personaje_crear(const char* nombre, int vida, int nivel, Arma* arma) {
    Personaje* nuevo_personaje = (Personaje*)malloc(sizeof(Personaje));
    if (!nuevo_personaje) return NULL;
    nuevo_personaje->nombre = (char*)malloc(strlen(nombre) + 1); //Chat me ayudo con esta nueva funcion, porque al armar una estrucuta con esto me dio esta herramienta para que capture el tamaño de la variable ingresada
    strcpy_s(nuevo_personaje->nombre, strlen(nombre) + 1, nombre);
    nuevo_personaje->vida = vida;
    nuevo_personaje->nivel = nivel;
    nuevo_personaje->arma = arma;
    nuevo_personaje->mostrar_estado = mostrar_estado_impl;
    nuevo_personaje->atacar = atacar_impl;
    return nuevo_personaje;
}


void Personaje_destruir(Personaje* this) {
    if (this) {
        free(this->nombre);
        // No destruimos el arma, ya que puede ser compartida
        free(this);
    }
}
