[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/-g_ni1Wx)
# Documentación del Proyecto
## Unidad 3

Estudiante:Luciana Gutiérrez Posada  
Id: 000507574
---

# Principios de POO
En este documento haré un registro de lo que comprendi y realice en cada uno de los principios fundamentales de POO, para asi evidenciar mi proceso con esta parte de la unidad 3 y al final responder las preguntas

## Abstracción 

- La parte conceptual la comprendi con facilidad, se trata de crear estructuras que representan los objetos junto con sus funciones, las clases en C se organixan con archivos .h y .c, ambos se necesitan mutuamente para poder funcionar

En el ejemplo creamos un personaje con ambos archivos, donde en el .h definimos una estructura con los atributos/propiedades de vida, nombre y nivel, y una funcion para mostrar el estado del personaje. 
Mas abajo tenemos una linea donde a Personaje se le pone un puntero en personaje crear y en el .c es donde le asignamos valores a los atributos. En el archivo .c definimos el nombre, vida y nivel del personaje con otra funcion
Luego con el fragmento anterior de crear personaje hacemos una nueva parte donde dice nuevo_personaje, que alli se almacena la info del personaje que creamos.
La parte de Personaje_destruir es para liberar la memoria dinamica. 
Me parecio importante evidenciar lo que entendi acerca del ejemplo puesto la mayoria de funciones o logica las usaremos mas adelante, a partir de aca solo evidenciare lo conceptual y las actividades practicas.

- Actividad práctica: 
**Crea una clase llamada Arma que tenga atributos como nombre, daño y alcance, y una función mostrar_info que imprima los detalles del arma. Implementa las funciones para crear y destruir un Arma.**

Arma.h 
```C
#ifndef ARMA_H
#define ARMA_H

typedef struct Arma {
    char* nombre;
    int daño;
    int alcance;
    void (*mostrar_info)(const struct Arma* this);
} Arma;

Arma* Arma_crear(const char* nombre, int daño, int alcance); //Función para crear arma
void Arma_destruir(Arma* this);// Funcion para destuir arma

#endif // ARMA_H

```
Aqui utilice el ejemplo como referencia, cree una estructura, cambie los atributos a los que se nos pedian en el ejemplo y la funcion, que la parte de imprimir los detalles la puse en el .c 

Arma.c
```C
#include "Arma.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void mostrar_info_impl(const Arma* this) {
    printf("Arma: %s | Daño: %d | Alcance: %d\n", this->nombre, this->daño, this->alcance);
}

Arma* Arma_crear(const char* nombre, int daño, int alcance) { //Funcion de crear arma
    Arma* nueva_arma = (Arma*)malloc(sizeof(Arma));
    if (!nueva_arma) return NULL;
    nueva_arma->nombre = (char*)malloc(strlen(nombre) + 1);
    strcpy_s(nueva_arma->nombre, strlen(nombre) + 1, nombre);
    nueva_arma->daño = daño;
    nueva_arma->alcance = alcance;
    nueva_arma->mostrar_info = mostrar_info_impl;
    return nueva_arma;
}

void Arma_destruir(Arma* this) {//funcion de destuir arma
    if (this) {
        free(this->nombre);
        free(this);
    }
}

```
Acá tambien me base en el codigo del ejemplo, cambie la parte de los atributos y la del nombre, puesto que la funcion strdup no funcionaba, inicialmente use solo strcpy_s pero, me toco cambiarlo con la ayuda de chat porque a medida que avanzaba en los otros temas la funcion perdio funcionalidad y sacaba error al compilar, y mas adelante llego a sacar problema al momento de ejcutar, pero no de compilar. 
La explicacion que me dio fue esta:  La razón por la que no puedes usar solo strcpy_s sin el tamaño de destino es porque strcpy_s es una función de copia de cadenas que incluye una verificación de seguridad. Esta función necesita que le pases el tamaño del buffer de destino para evitar desbordamientos de búfer, que podrían causar fallos de seguridad o errores en el programa.

## Encapsulamiento 
- En lo conceptual de esta parte entendi que se ocultan partes de una clase y solo se deja abierto lo que se necesita, para facilitar el mantenimiento y proteger los datos, en C se ponen las declaraciones en los .h y las definiciones en los .c, se usa el modificador static en los atchivos .c para limitar el alcance a ese archivo, impidiendo su acceso desde otros, solo se puede ver y usar donde se declaro la variable o funcion que lleva static. 

- Actividad práctica: 
**Refactoriza el código de Arma que creaste anteriormente para que las funciones internas o variables auxiliares sean static y no estén expuestas en el archivo de cabecera.**

Arma.c 
```C
static void mostrar_info_impl(const Arma* this) {
    printf("Arma: %s | Daño: %d | Alcance: %d\n", this->nombre, this->daño, this->alcance);
}
```
Primero fui a Arma.h y verifique que la unica funcion o variable que no se usa del .c en el .h es la de mostrar_info_impl, por lo cual me dirigi al .c y encapsule esta funcion puesto que solo se usa en este archivo

## Herencia 
- La herencia no es directamente soportada por C, pero se explica que esto se puede simular incluyendo una estructura dentro de otra, porque la herencia en si se trata de crear clases nuevas basandose en clases existentes. 

En el ejemplo se escribio "Personaje base;" para copiar la estructura de personaje, pero se agrego un int fuerza, por lo cual la funcion mostrat_estado_impl se debe de reescribir para mostrar la fuerza.

- Actividad Práctica: 

**Crea una estructura Mago que herede de Personaje y sobreescriba la función mostrar_estado para incluir un atributo específico como mana. Implementa las funciones necesarias para crear y destruir un Mago.**


## Polimorfismo

- El polimorfismo en si permite que varias clases se puedan tratar como instancias de una clase base, y que las funciones que se llaman se comporten de distintas maneras dependiendo de la clase REAL del objeto, para lograr esto en C se usan punteros a la clase base y a funciones. 


# Actividad 2

1. **Identificación de Clases:**
    - Analiza las entidades principales de tu juego (como personajes, objetos interactivos, entornos) e identifica las clases que representarían estas entidades.

    En este juego tenemos ladrillos, bola y paleta, las clases que creo que podria establecer serian: 

        - Bola 
        - Paleta
        - Ladrillos
        - Game (sería el main)
    - Define cuáles de estas clases serán *principales* (padres) y cuáles serán *derivadas* (hijas), siguiendo un enfoque de reutilización de código.

    Tendria una clase padre donde pondria los atributos de posicion en X y Y, ancho y alto, puesto que las 3 figuras se conforman por rectangulos o cuadrados entonces comparten estos atributos, todavia no se si hacer una clase Entity o usar una anterior como las de los objetos. 
    Las clases derivadas serian bola, paleta y ladrillo

        - Bola: 
            
            Atributos:Además de los de la clase Entity
            int dx (velocidad en x)
            int dy (velocidad en y)
            int radio
            Métodos: 
            Update () (actuliza posicion y verifica colisiones)
            render ()

        - Paleta: 
            Atributos: Además de los de Entity
            int speed (velocidad de movimiento)
            Métodos:
            move () (mueve la paleta con la entrada de teclado)
            render()
        - Ladrillos: 
            Atributos: Los de Entity
            bool destroyed (marca si se destruyo el ladrillo)
            Métodos: 
            check_colission () (verifica colision de la bola)
            render()
            process_input()

        Clase Game: 

        Métodos: initialize()

        Relaciones:
        
        Herencia: Ball, Paddle, y Brick heredan de Entity, lo que permite reutilizar los métodos y atributos comunes como move() y check_collision().

        Agregación: La clase Game administra las instancias de Ball, Paddle, y una lista o matriz de Brick.
# Diagrama UML: 
![alt text](<Clase UML.jpeg>)

# Codigo de brick breaker a POO

Primero cree los archivos .h y .c de cada clase, como lo son entity, bola,ladrillo y paleta. 
De ahi empece con las estructuras y la herencia desde Entity, al hacer estoy vi que bola maneja radio, no ancho ni alto, entonces recorde que la bola de mi juego no es un circulo si no un cuadrado, entonces me di cuenta que podia cambiar radio por estos atributos y usar la herencia a la perfeccion. 

Empece con bola, hice la herencia de Entity, cree los constructores y pase la funcion de update_ball a la clase de bola.c