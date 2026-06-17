<div align="center">

# 🌊 Simulación de Cuenca Fluvial con Comercio Interurbano
### *River Basin Simulation with Inter-City Trading*

[![C++](https://img.shields.io/badge/C++-11-blue?logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Compiler](https://img.shields.io/badge/Compiler-g++-orange?logo=gnu&logoColor=white)](https://gcc.gnu.org/)
[![Documentation](https://img.shields.io/badge/Docs-Doxygen-green?logo=readthedocs&logoColor=white)](https://ishaaakkk.github.io/PRO2/html/index.html)
[![Course](https://img.shields.io/badge/Course-PRO2%20·%20FIB%20UPC-red)](https://www.fib.upc.edu/)
[![License](https://img.shields.io/badge/License-Academic-lightgrey)](./Docs/)

<br/>

> **Autor / Author:** Ishak Felfoul  
> **Asignatura / Course:** Programació 2 (PRO2) — Facultat d'Informàtica de Barcelona · UPC  
> **Documentación / Documentation:** [📚 Ver Doxygen →](https://ishaaakkk.github.io/PRO2/html/index.html)

</div>

---

## 🇪🇸 Español

---

### 📋 Descripción General

Este proyecto implementa una simulación completa de una **cuenca fluvial** donde un conjunto de ciudades, situadas en los nodos de un árbol binario (representando fuentes, confluencias y desembocadura de ríos), gestionan inventarios de productos con peso y volumen, y comercian entre sí a través de un **barco** que recorre la cuenca de forma óptima.

El problema central consiste en:
- Modelar la topología de una cuenca como un **árbol binario** de ciudades.
- Gestionar los inventarios de múltiples productos en cada ciudad (unidades disponibles y unidades necesarias).
- Implementar las operaciones de **comercio directo** entre ciudades y de **redistribución** global a lo largo de toda la cuenca.
- Calcular la **ruta óptima** del barco para maximizar el número de intercambios de productos en un único viaje.

---

### 🎯 Objetivos y Competencias de Programació 2 (PRO2)

Este proyecto aplica los siguientes conceptos clave exigidos por la asignatura:

| Competencia | Aplicación en el Proyecto |
|---|---|
| **Programación Orientada a Objetos** | Cuatro clases con encapsulación, atributos privados y métodos bien definidos |
| **Árboles Binarios** | La cuenca se representa con `BinTree<string>` para modelar la jerarquía fluvial |
| **Gestión dinámica de datos** | Uso de `std::map`, `std::vector` y `std::list` de la STL |
| **Recursividad** | `leer_arbol`, `redistribuir_aux` y `mejor_ruta` son funciones puramente recursivas |
| **Modularidad y separación interfaz/implementación** | Separación estricta en archivos `.hh` (spec.) y `.cc` (impl.) |
| **Pre/Post condiciones** | Toda función documentada con `\pre` y `\post` según el estilo Doxygen |
| **Algoritmos de optimización** | Búsqueda de la ruta óptima del barco con criterios de desempate (longitud, preferencia derecha) |
| **Complejidad y eficiencia** | Uso de `map` ordenado para recorridos eficientes en la operación de comercio entre ciudades |

---

### 🏗️ Arquitectura y Estructura de Archivos

```
practica/
│
├── 📂 src/                 # Código fuente / Source code
│   ├── 📄 program.cc       # Punto de entrada. Bucle principal de lectura de comandos
│   ├── 📦 Cuenca.hh/.cc    # Clase principal. Gestiona la cuenca fluvial
│   ├── 🏙️ Ciudad.hh/.cc    # Representa una ciudad con su inventario
│   ├── 🚢 Barco.hh/.cc     # Lógica y parámetros del barco
│   ├── 📦 Productos.hh/.cc # Catálogo global de productos
│   └── 📄 BinTree.hh       # Árbol binario genérico (FIB UPC)
│
├── 📂 docs/                # Documentación en PDF / PDF documentation
│   ├── Enunciado.pdf       # Enunciado oficial de la práctica
│   ├── Avaluació.pdf       # Criterios de evaluación
│   └── justificacion_funciones.pdf # Justificación de decisiones de diseño
│
├── 📂 test/                # Juego de pruebas / Test case files
│   ├── entrada.txt         # Entrada de ejemplo comentada
│   └── salida_esperada.txt # Salida correcta del programa
│
├── 📂 html/                # Documentación Doxygen generada (HTML navegable)
│   └── index.html          # Punto de entrada de la documentación
│
├── 🔧 Makefile             # Sistema de compilación modular con flags de optimización
└── 📄 README.md            # Este archivo
```

#### Relación entre clases

```
         ┌─────────────┐
         │   Cuenca    │  ←── clase principal / controladora
         │  (árbol +   │
         │   mapa)     │
         └──────┬──────┘
       uses     │     uses
    ┌───────────┼───────────┐
    ▼           ▼           ▼
┌────────┐ ┌────────┐ ┌──────────┐
│ Ciudad │ │ Barco  │ │Productos │
│(map)   │ │(list)  │ │(vector)  │
└────────┘ └────────┘ └──────────┘
```

---

### 🛠️ Tecnologías y Herramientas

| Herramienta | Detalle |
|---|---|
| **Lenguaje** | C++11 |
| **Compilador** | `g++` (GCC) |
| **Flags de compilación** | `-O2 -Wall -Wextra -Werror -std=c++11` |
| **Estructura de datos** | `BinTree<T>` (árbol binario genérico propio), `std::map`, `std::vector`, `std::list`, `std::pair` |
| **Documentación** | Doxygen 1.9.1 |
| **Sistema de build** | GNU Make |
| **Estándar de código** | Separación `.hh`/`.cc`, pre/postcondiciones Doxygen |

---

### ⚙️ Requisitos e Instalación

#### Requisitos previos

- **Sistema operativo:** Linux / macOS / WSL (Windows)
- **Compilador:** `g++` con soporte para C++11
- **Make:** GNU Make

```bash
# Verificar que g++ está disponible
g++ --version

# Verificar que make está disponible
make --version
```

#### Compilar el proyecto

```bash
# Clonar o descargar el repositorio
git clone <url-del-repositorio>
cd practica

# Compilar el proyecto completo (genera program.exe y limpia .o)
make

# O compilar manualmente con todos los flags
g++ -o program.exe program.cc Cuenca.cc Ciudad.cc Barco.cc Productos.cc \
    -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror \
    -Wno-sign-compare -std=c++11 -fno-extended-identifiers
```

#### Ejecutar el programa

El programa lee la entrada desde `stdin` y escribe la salida en `stdout`:

```bash
# Ejecutar con entrada manual
./program.exe

# Ejecutar con un archivo de entrada
./program.exe < entrada.txt

# Ejecutar y guardar la salida
./program.exe < entrada.txt > salida.txt
```

#### Formato de entrada

```
<num_productos>
<peso_1> <volumen_1>
...
<árbol_cuenca en preorden, # indica nodo vacío>
<id_prod_comprar> <cant_comprar> <id_prod_vender> <cant_vender>
<comandos...>
fin
```

#### Ver la documentación Doxygen

```bash
# Abrir en el navegador
xdg-open html/index.html        # Linux
open html/index.html            # macOS
```

O directamente en GitHub Pages: **[📚 Ver documentación en vivo →](https://ishaaakkk.github.io/PRO2/html/index.html)**

---

### ✨ Características Principales (Features)

- **🌲 Modelado de cuenca fluvial como árbol binario** — La jerarquía del río (fuentes, confluencias, desembocadura) se lee de forma recursiva y se almacena en un `BinTree<string>`.

- **🏙️ Gestión de inventarios por ciudad** — Cada ciudad mantiene un `map` ordenado de productos con sus unidades disponibles y necesarias, además del peso y volumen total acumulados.

- **🔄 Comercio bilateral** — Dos ciudades intercambian productos en un recorrido lineal de sus inventarios ordenados (complejidad O(n)), cediendo excedentes a quien los necesita.

- **🌐 Redistribución global** — La operación `redistribuir` recorre el árbol en preorden (desembocadura → fuentes) para que cada ciudad comercie con sus ciudades adyacentes río arriba.

- **🗺️ Ruta óptima del barco** — El algoritmo `mejor_ruta` calcula de forma recursiva la ruta que maximiza los intercambios. En caso de empate en intercambios, selecciona la ruta más corta; en segundo empate, prefiere la rama derecha del árbol.

- **⚡ Ejecución del viaje** — `hacer_ruta` ejecuta el viaje encontrado, actualizando los inventarios de cada ciudad de la ruta en tiempo real.

- **📝 Historial de viajes del barco** — El barco registra cronológicamente la última ciudad de cada viaje donde hubo intercambio.

- **🖥️ Interfaz de comandos** — El programa implementa un intérprete de comandos (tanto en nombre largo como en alias corto) con manejo de errores robusto:
  - `leer_rio` / `lr` — Recarga la estructura de la cuenca
  - `leer_inventario` / `li` — Lee el inventario de una ciudad
  - `leer_inventarios` / `ls` — Lee inventarios de múltiples ciudades
  - `modificar_barco` / `mb` — Modifica los parámetros del barco
  - `escribir_barco` / `eb` — Muestra el estado del barco
  - `poner_prod` / `pp` — Añade un producto al inventario de una ciudad
  - `modificar_prod` / `mp` — Modifica las unidades de un producto en una ciudad
  - `quitar_prod` / `qp` — Elimina un producto del inventario de una ciudad
  - `consultar_prod` / `cp` — Consulta las unidades de un producto en una ciudad
  - `comerciar` / `co` — Realiza un comercio directo entre dos ciudades
  - `redistribuir` / `re` — Ejecuta la redistribución global de la cuenca
  - `hacer_viaje` / `hv` — Lanza el barco en su ruta óptima
  - `escribir_ciudad` / `ec` — Muestra el inventario completo de una ciudad
  - `agregar_productos` / `ap` — Amplía el catálogo de productos
  - `escribir_producto` / `ep` — Muestra los datos de un producto
  - `consultar_num` / `cn` — Consulta el número total de productos

---

---

## 🇬🇧 English

---

### 📋 General Description

This project implements a complete simulation of a **river basin** where a set of cities — placed at the nodes of a binary tree (representing sources, confluences, and the river mouth) — manage product inventories with weight and volume, and trade with each other through a **boat** that travels the basin along an optimal route.

The core problem consists of:
- Modelling the topology of a river basin as a **binary tree** of cities.
- Managing inventories of multiple products per city (available units and required units).
- Implementing **direct trade** between cities and a global **redistribution** across the entire basin.
- Computing the **optimal route** for the boat to maximise the number of product exchanges in a single trip.

---

### 🎯 Learning Objectives & PRO2 Competencies Applied

| Competency | Application in the Project |
|---|---|
| **Object-Oriented Programming** | Four well-encapsulated classes with private attributes and clean public interfaces |
| **Binary Trees** | The basin is represented as `BinTree<string>` to model the river hierarchy |
| **Dynamic Data Management** | Use of `std::map`, `std::vector`, and `std::list` from the STL |
| **Recursion** | `leer_arbol`, `redistribuir_aux`, and `mejor_ruta` are purely recursive functions |
| **Modularity** | Strict separation into `.hh` (specification) and `.cc` (implementation) files |
| **Pre/Post Conditions** | Every function documented with `\pre` and `\post` in Doxygen style |
| **Optimisation Algorithms** | Optimal boat route search with tiebreaker criteria (length, right-branch preference) |
| **Efficiency** | Sorted `map` structure enables efficient parallel traversal in bilateral trade operations |

---

### 🏗️ Architecture & File Structure

```
practica/
│
├── 📂 src/                 # Source code
│   ├── 📄 program.cc       # Entry point. Main command-reading loop
│   ├── 📦 Cuenca.hh/.cc    # Main class. Manages the basin operations
│   ├── 🏙️ Ciudad.hh/.cc    # Represents a city with its product inventory
│   ├── 🚢 Barco.hh/.cc     # Represents the boat and its travel log
│   ├── 📦 Productos.hh/.cc # Global product catalogue
│   └── 📄 BinTree.hh       # Generic binary tree (FIB UPC)
│
├── 📂 docs/                # PDF documentation
│   ├── Enunciado.pdf       # Official assignment statement
│   ├── Avaluació.pdf       # Evaluation rubric
│   └── justificacion_funciones.pdf # Implementation decision justification
│
├── 📂 test/                # Test case files
│   ├── entrada.txt         # Annotated example input
│   └── salida_esperada.txt # Correct program output
│
├── 📂 html/                # Generated Doxygen documentation (navigable HTML)
│   └── index.html          # Documentation entry point
│
├── 🔧 Makefile             # Modular build system with optimisation flags
└── 📄 README.md            # This file
```

---

### 🛠️ Technologies & Tools

| Tool | Details |
|---|---|
| **Language** | C++11 |
| **Compiler** | `g++` (GCC) |
| **Compilation flags** | `-O2 -Wall -Wextra -Werror -std=c++11` |
| **Data structures** | Custom generic `BinTree<T>`, `std::map`, `std::vector`, `std::list`, `std::pair` |
| **Documentation** | Doxygen 1.9.1 |
| **Build system** | GNU Make |
| **Code standard** | `.hh`/`.cc` separation, Doxygen pre/postconditions |

---

### ⚙️ Requirements & Installation

#### Prerequisites

- **OS:** Linux / macOS / WSL (Windows)
- **Compiler:** `g++` with C++11 support
- **Make:** GNU Make

```bash
# Check g++ is available
g++ --version

# Check make is available
make --version
```

#### Build the project

```bash
# Clone or download the repository
git clone <repository-url>
cd practica

# Build the full project (generates program.exe and cleans .o files)
make

# Or compile manually with all flags
g++ -o program.exe program.cc Cuenca.cc Ciudad.cc Barco.cc Productos.cc \
    -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror \
    -Wno-sign-compare -std=c++11 -fno-extended-identifiers
```

#### Run the program

The program reads from `stdin` and writes to `stdout`:

```bash
# Run with manual input
./program.exe

# Run with an input file
./program.exe < input.txt

# Run and save output
./program.exe < input.txt > output.txt
```

#### Input format

```
<num_products>
<weight_1> <volume_1>
...
<basin_tree in preorder, # denotes empty node>
<buy_prod_id> <buy_qty> <sell_prod_id> <sell_qty>
<commands...>
fin
```

#### View Doxygen documentation

```bash
# Open in browser
xdg-open html/index.html        # Linux
open html/index.html            # macOS
```

Or directly via GitHub Pages: **[📚 View live documentation →](https://ishaaakkk.github.io/PRO2/html/index.html)**

---

### ✨ Key Features

- **🌲 River basin modelled as a binary tree** — The river hierarchy (sources, confluences, mouth) is read recursively and stored in a `BinTree<string>`.

- **🏙️ Per-city inventory management** — Each city maintains a sorted `map` of products with available and required units, plus accumulated total weight and volume.

- **🔄 Bilateral trading** — Two cities exchange products in a single linear pass over their sorted inventories (O(n) complexity), transferring surpluses to those in need.

- **🌐 Global redistribution** — The `redistribuir` operation traverses the tree in preorder (mouth → sources) so each city trades with its upstream neighbours.

- **🗺️ Optimal boat routing** — The `mejor_ruta` algorithm recursively computes the route maximising exchanges. On ties in exchanges, it picks the shorter route; on a second tie, it prefers the right branch.

- **⚡ Trip execution** — `hacer_ruta` executes the computed journey, updating each city's inventory in real time.

- **📝 Boat travel log** — The boat keeps a chronological record of the last city visited per trip where an exchange took place.

- **🖥️ Command interpreter** — The program implements a command interface (both full names and short aliases) with robust error handling:
  - `leer_rio` / `lr` — Reloads the basin structure
  - `leer_inventario` / `li` — Reads a city's inventory
  - `leer_inventarios` / `ls` — Reads inventories for multiple cities
  - `modificar_barco` / `mb` — Updates the boat's parameters
  - `escribir_barco` / `eb` — Prints the boat's current state
  - `poner_prod` / `pp` — Adds a product to a city's inventory
  - `modificar_prod` / `mp` — Modifies product units in a city
  - `quitar_prod` / `qp` — Removes a product from a city's inventory
  - `consultar_prod` / `cp` — Queries product units in a city
  - `comerciar` / `co` — Performs direct trade between two cities
  - `redistribuir` / `re` — Runs the global basin redistribution
  - `hacer_viaje` / `hv` — Launches the boat on its optimal route
  - `escribir_ciudad` / `ec` — Displays a city's full inventory
  - `agregar_productos` / `ap` — Extends the product catalogue
  - `escribir_producto` / `ep` — Displays a product's data
  - `consultar_num` / `cn` — Queries the total number of products

---

### 🧪 Test Case / Juego de Pruebas

Los archivos de ejemplo se encuentran en la carpeta [`test/`](./test/).  
*The example files are located in the [`test/`](./test/) folder.*

```bash
# Ejecutar el juego de pruebas / Run the test case
./program.exe < test/entrada.txt

# Comparar con la salida esperada / Compare against expected output
./program.exe < test/entrada.txt | diff - test/salida_esperada.txt && echo "OK ✅" || echo "DIFERENCIAS ❌"
```

#### Estructura de la cuenca / Basin structure

La cuenca tiene **5 ciudades** dispuestas en un árbol binario. A es la desembocadura.  
*The basin has 5 cities arranged in a binary tree. A is the river mouth.*

```
          A          ← desembocadura / river mouth
         / \
        B   E        ← afluentes / tributaries
       / \
      C   D          ← fuentes / sources
```

> Preorder (formato entrada): `A B C # # D # # E # #`

#### Catálogo de productos / Product catalogue

| ID | Peso / Weight | Volumen / Volume |
|----|--------------|-----------------|
| 1  | 2            | 3               |
| 2  | 4            | 1               |
| 3  | 1            | 2               |

#### Entrada anotada / Annotated input ([`test/entrada.txt`](./test/entrada.txt))

```
3                        ← 3 productos
2 3                      ← prod 1: peso=2, vol=3
4 1                      ← prod 2: peso=4, vol=1
1 2                      ← prod 3: peso=1, vol=2
A B C # # D # # E # #   ← árbol de la cuenca (preorden)
1 10 2 5                 ← barco: compra prod1(×10), vende prod2(×5)

leer_inventarios         ← carga inventarios de B, C, D, E
B 2
  1 10 5                 ←   B tiene 10 de prod1, necesita 5
  2  0 8                 ←   B tiene  0 de prod2, necesita 8
C 2
  1  0 3                 ←   C tiene  0 de prod1, necesita 3
  2  7 2                 ←   C tiene  7 de prod2, necesita 2
D 1
  1  5 8                 ←   D tiene  5 de prod1, necesita 8
E 1
  2  3 1                 ←   E tiene  3 de prod2, necesita 1
#

escribir_barco           ← barco: compra=1×10, vende=2×5
consultar_num            ← 3 productos en catálogo
escribir_producto 1      ← prod 1: peso=2, vol=3
escribir_producto 2      ← prod 2: peso=4, vol=1
escribir_producto 3      ← prod 3: peso=1, vol=2
escribir_ciudad A        ← A vacía al inicio
escribir_ciudad B
escribir_ciudad C
escribir_ciudad D
escribir_ciudad E

comerciar B D            ← B y D comercian entre sí
escribir_ciudad B
escribir_ciudad D

redistribuir             ← redistribución global de la cuenca
escribir_ciudad A
escribir_ciudad B
escribir_ciudad C
escribir_ciudad D
escribir_ciudad E

hacer_viaje              ← barco hace su ruta óptima
escribir_barco           ← historial de viajes

poner_prod A 3 2 4       ← añadir prod3 a A (tiene=2, necesita=4)
escribir_ciudad A
quitar_prod A 3          ← quitar prod3 de A
escribir_ciudad A
modificar_prod B 2 3 6   ← modificar prod2 en B (tiene=3, necesita=6)
escribir_ciudad B
consultar_prod B 2       ← consultar estado de prod2 en B

hacer_viaje              ← segundo viaje del barco
escribir_barco

fin
```

#### Salida esperada / Expected output ([`test/salida_esperada.txt`](./test/salida_esperada.txt))

```
#leer_inventarios
#escribir_barco
1 10 2 5
#consultar_num
3
#escribir_producto 1
1 2 3
#escribir_producto 2
2 4 1
#escribir_producto 3
3 1 2
#escribir_ciudad A
0 0
#escribir_ciudad B
1 10 5
2 0 8
20 30
#escribir_ciudad C
1 0 3
2 7 2
28 7
#escribir_ciudad D
1 5 8
10 15
#escribir_ciudad E
2 3 1
12 3
#comerciar B D
#escribir_ciudad B
1 7 5
2 0 8
14 21
#escribir_ciudad D
1 8 8
16 24
#redistribuir
#escribir_ciudad A
0 0
#escribir_ciudad B
1 5 5
2 5 8
30 20
#escribir_ciudad C
1 2 3
2 2 2
12 8
#escribir_ciudad D
1 8 8
16 24
#escribir_ciudad E
2 3 1
12 3
#hacer_viaje
3
#escribir_barco
1 10 2 5
B
#poner_prod A 3
2 4
#escribir_ciudad A
3 2 4
2 4
#quitar_prod A 3
0 0
#escribir_ciudad A
0 0
#modificar_prod B 2
22 18
#escribir_ciudad B
1 5 5
2 3 6
22 18
#consultar_prod B 2
3 6
#hacer_viaje
3
#escribir_barco
1 10 2 5
B
B
```

#### Análisis de operaciones clave / Key operation analysis

| Operación | Resultado destacado |
|-----------|---------------------|
| `comerciar B D` | B cede 3 unidades de prod1 a D (sobrante B→D), peso B: 20→14 |
| `redistribuir` | A redistribuye con B y E; B absorbe excedente de C en prod2 |
| `hacer_viaje` (1º) | Ruta óptima: **A→B** (3 intercambios); el barco compra prod1 de B |
| `hacer_viaje` (2º) | Ruta óptima: **A→B** de nuevo (3 intercambios); barco visita B otra vez |

---

<div align="center">

*Developed as part of the PRO2 course at FIB — Facultat d'Informàtica de Barcelona · UPC*

</div>
