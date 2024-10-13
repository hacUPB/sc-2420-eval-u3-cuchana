#include "Ladrillo.h"
#include "Bola.h"


Ladrillo* crear_ladrillo(int x, int y, int height, int width) {
    Ladrillo* ladrillo = (Ladrillo*)malloc(sizeof(Ladrillo));
    if (!ladrillo) return NULL;
    ladrillo->base.x = x;
    ladrillo->base.y = y;
    ladrillo->base.width = width;
    ladrillo->base.height = height;
    ladrillo->destruido = false; // Asegúrate de inicializarlo a false
    ladrillo->base.color = (SDL_Color){ 255, 0, 0, 255 }; // Color rojo
    return ladrillo;
}

int score = 0;


// Función para verificar la colisión entre la bola y los ladrillos
void check_bola_brick_collision(Bola* bola, Ladrillo* ladrillos[5][10]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 10; j++) {
            Ladrillo* ladrillo = ladrillos[i][j]; // Cambia a puntero directo
            if (!ladrillo->destruido) {
                // Verificación de colisión entre la bola y el ladrillo
                if (bola->base.x < ladrillo->base.x + ladrillo->base.width &&
                    bola->base.x + bola->base.width > ladrillo->base.x &&
                    bola->base.y < ladrillo->base.y + ladrillo->base.height &&
                    bola->base.y + bola->base.height > ladrillo->base.y) {

                    // Si colisiona, destruimos el ladrillo y cambiamos la dirección de la bola
                    ladrillo->destruido = true;
                    bola->dy *= -1;  // Cambiamos la dirección vertical de la bola
                    score += 10;     // Aumentamos el puntaje
                    printf("Puntaje: %d\n", score); // Mostrar el puntaje
                    
                }
            }
        }
    }
}


void render_ladrillo(Ladrillo* ladrillo, SDL_Renderer* renderer) {
    if (!ladrillo->destruido) {
        render_entity((Entity*)ladrillo, renderer); // Llama a la función de renderizado de la entidad
    }
}

void destruir_ladrillo(Ladrillo* this) {
    free(this);
}


