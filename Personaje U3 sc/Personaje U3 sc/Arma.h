#ifndef ARMA_H
#define ARMA_H

typedef struct Arma {
    char* nombre;
    int daño;
    int alcance;
    void (*mostrar_info)(const struct Arma* this);
} Arma;

Arma* Arma_crear(const char* nombre, int daño, int alcance);
void Arma_destruir(Arma* this);

#endif // ARMA_H

