#include "Personaje.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Arma.h"
#include "Equipo.h"
#include <stdio.h>

int main() {

    // Crear armas
    Arma* espada = Arma_crear("Espada", 50, 5);
    Arma* arco = Arma_crear("Arco", 30, 10);

    // Crear personajes
    Guerrero* guerrero = Guerrero_crear("Artemo", 100, 10, 80, espada);
    Mago* mago = Mago_crear("Tanna", 80, 12, 120, arco);

    // Crear equipo y agregar personajes
    Equipo* equipo = Equipo_crear();
    Equipo_agregar_personaje(equipo, (Personaje*)guerrero);
    Equipo_agregar_personaje(equipo, (Personaje*)mago);

    // Mostrar estado del equipo
    Equipo_mostrar_estado(equipo);

    // Llamar a atacar para cada personaje en el equipo
    for (int i = 0; i < equipo->cantidad_personajes; ++i) {
        equipo->personajes[i]->atacar(equipo->personajes[i]);
    }

    // Liberar memoria
    Equipo_destruir(equipo);
    Arma_destruir(espada);
    Arma_destruir(arco);

    return 0;
}
