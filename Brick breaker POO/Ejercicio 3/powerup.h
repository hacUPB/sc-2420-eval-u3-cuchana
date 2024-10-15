#ifndef POWERUP_H
#define POWERUP_H

#include "Entity.h"
#include "Bola.h"
#include <stdbool.h>

typedef struct PowerUp {
    Entity base;
    bool activo;
} PowerUp;

extern PowerUp cuadritos_powerup[5];  // Ajustado a 5 cuadritos

PowerUp* crear_powerup_cuadrito(int x, int y, int width, int height);

void generar_lluvia_powerup();
void actualizar_lluvia_powerup(Bola* bola, int* score);
void render_lluvia_powerup(SDL_Renderer* renderer);
#endif

