
# Proyecto de C++ - Thief and Policeman Race (Ladrón y Policía)

## Descripción del Proyecto

Este proyecto implementa una versión simple del juego (Ladrón y Policía). Dos jugadores, representados por distintos caracteres personalizables, compiten para llegar primero a la casilla final (casilla 20) de un tablero en forma de espiral. El juego simula el lanzamiento de un dado para determinar cuántas casillas avanza cada jugador en su turno. El tablero se muestra visualmente en cada turno, y el juego anuncia al ganador una vez que uno de los jugadores alcanza o supera la meta.

El juego utiliza estructuras de control como `if`, `switch`, y bucles `while` y `for` para gestionar el flujo del juego, la interacción del usuario y la representación visual del tablero y el dado.

## Equipo

- **Equipo: Los compiladores** 

### Integrantes del equipo

1. **Angel Gustavo Monterrosa Cisneros**
   **00048825**

2. **Emerson Eleazar Moran Ramos**
   **00083925**

3. **Samuel Andre Moran Escobar**
   **00133225**

4. **Luis Jose Murcia Portillo**
   **00249025**

## Explicación del Funcionamiento del Juego


1.  **Inicio del Juego:**
    * Al iniciar, se presenta un menú principal con las opciones "Jugar", "Escoger Personaje" y "Salir".
    * Si seleccionas "Jugar", ambos jugadores comienzan en la casilla 1.
    * Si seleccionas "Escoger Personaje", cada jugador puede elegir un símbolo (`@`, `$`, `!`, `*`) para representarse en el tablero. Por defecto, los personajes son `@` y `$`.

2.  **Turnos:**
    * El juego alterna automáticamente entre el Jugador 1 y el Jugador 2.
    * En cada turno, se muestra el estado actual del tablero.
    * Se le indica al jugador actual que presione `ENTER` para lanzar el dado.
    * El dado genera un número aleatorio entre 1 y 6.
    * El jugador avanza el número de casillas indicado por el dado.

3.  **Movimiento en el Tablero:**
    * El tablero es una matriz 6x6 que simula un recorrido numérico del 1 al 20, en forma de espiral.
    * Las funciones internas del juego (`casilla_a_coordenadas`) se encargan de traducir el número de la casilla a las coordenadas de fila y columna en la matriz.
    * Cuando un jugador se mueve, su personaje se coloca en la nueva casilla, y la casilla anterior restaura su número original.

4.  **Condición de Victoria:**
    * El primer jugador en alcanzar o superar la casilla 20 gana el juego. Una vez que un jugador gana, el juego termina y se anuncia al ganador.

## Instrucciones de Ejecución Detalladas


Para compilar y ejecutar este proyecto, necesitarás un compilador de C++ (como g++).


.  **Compila el código:**
    Este proyecto está estructurado con múltiples archivos (`Main.cpp`, `Funciones.cpp`, `Header.h`).
    Puedes compilarlo usando un comando como este:

   
    g++ -o juego_ladrón_policía "Main.cpp" "Funciones.cpp" -I.
    
    * **`-o juego_ladrón_policía`**: Especifica el nombre del ejecutable de salida.
    * **`"Main.cpp"` `"Funciones.cpp"`**: Son los archivos fuente que se van a compilar. Asegúrate de incluir los nombres exactos de los archivos.
    * **`-I.`**: Le dice al compilador que busque archivos de encabezado (`.h`) en el directorio actual.


4.  **Ejecuta el juego:**
    ./juego_ladrón_policía

Ahora podrás interactuar con el juego a través de la consola, seleccionando opciones del menú y lanzando el dado.