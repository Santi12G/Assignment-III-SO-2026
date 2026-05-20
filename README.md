# Assignment III Sistemas Operativos 2026


La carpeta Parte1 corresponde a la primera parte del assignment III donde estará la solución de cada punto cada uno en un archivo .cpp separado.

Por otra parte la carpeta Parte2 contiene la implementacion correspondiente de lo que se solicitaba para la segunda parte de este trabajo.


# Parte 1 - Programas en C++

La carpeta `Parte1` contiene programas desarrollados en C++ relacionados con el uso de punteros, referencias, arreglos y memoria dinámica.

---

# Requisitos

Antes de ejecutar los programas, asegúrese de tener instalado:

- g++
- Un compilador compatible con C++11 o superior

Para verificar la instalación:

```bash
g++ --version
```

---

# Estructura de la carpeta

```text
Parte1/
│
├── punto1.cpp
├── punto2.cpp
├── punto3.cpp
└── punto4.cpp
```

---

# Cómo ejecutar los programas

Primero ingrese a la carpeta `Parte1`:

```bash
cd Parte1
```

---

# Ejecutar punto1.cpp

Este programa muestra cómo utilizar punteros para modificar el valor de una variable mediante acceso indirecto.

## Compilar

```bash
g++ punto1.cpp -o punto1
```

## Ejecutar

### Linux / Mac

```bash
./punto1
```

### Windows

```bash
punto1.exe
```

---

# Ejecutar punto2.cpp

Este programa muestra la diferencia entre el uso de punteros y referencias en C++, modificando el valor de una variable y mostrando sus direcciones de memoria. :contentReference[oaicite:0]{index=0}

## Compilar

```bash
g++ punto2.cpp -o punto2
```

## Ejecutar

### Linux / Mac

```bash
./punto2
```

### Windows

```bash
punto2.exe
```

---

# Ejecutar punto3.cpp

Este programa utiliza punteros para recorrer y modificar un arreglo, mostrando además las direcciones de memoria de cada elemento.

## Compilar

```bash
g++ punto3.cpp -o punto3
```

## Ejecutar

### Linux / Mac

```bash
./punto3
```

### Windows

```bash
punto3.exe
```

---

# Ejecutar punto4.cpp

Este programa implementa memoria dinámica para crear una matriz bidimensional usando punteros dobles (`int**`).

## Compilar

```bash
g++ punto4.cpp -o punto4
```

## Ejecutar

### Linux / Mac

```bash
./punto4
```

### Windows

```bash
punto4.exe
```

---

# Explicación General

## punto1.cpp

- Declara una variable entera.
- Crea un puntero hacia dicha variable.
- Modifica el valor usando desreferenciación.
- Muestra direcciones de memoria.

---

## punto2.cpp

- Declara una variable entera.
- Usa un puntero y una referencia hacia la misma variable.
- Modifica el valor usando ambos métodos.
- Muestra las direcciones de memoria correspondientes.

---

## punto3.cpp

- Declara un arreglo de enteros.
- Recorre el arreglo usando punteros.
- Modifica sus valores.
- Imprime contenido y direcciones de memoria.

---

## punto4.cpp

- Solicita filas y columnas.
- Reserva memoria dinámicamente.
- Permite ingresar valores a la matriz.
- Imprime la matriz y sus direcciones de memoria.
- Libera correctamente la memoria usando `delete[]`.

---

---

# Parte 2 - Algoritmos de Planificación de Disco

La carpeta `Parte2` contiene programas relacionados con algoritmos de planificación de disco y visualización de resultados.

## Estructura de la carpeta

```text
Parte2/
│
├── parte2,2.cpp
└── visualizacion.py
```

---

# Requisitos

## Para el programa en C++

Instalar:

- g++
- Compilador compatible con C++11 o superior

Verificar instalación:

```bash
g++ --version
```

---

## Para el programa en Python

Instalar:

- Python 3
- matplotlib

Verificar Python:

```bash
python --version
```

Instalar matplotlib:

```bash
pip install matplotlib
```

---

# Cómo ejecutar los programas

Primero ingresar a la carpeta `Parte2`:

```bash
cd Parte2
```

---

# Ejecutar parte2,2.cpp

Este programa implementa los algoritmos de planificación de disco:

- FCFS
- SCAN
- C-SCAN

Además, genera 1000 solicitudes aleatorias de cilindros y calcula el movimiento total del cabezal del disco para cada algoritmo. 

## Compilar

```bash
g++ "parte2,2.cpp" -o parte2
```

## Ejecutar

El programa requiere recibir la posición inicial del cabezal como argumento.

### Linux / Mac

```bash
./parte2 2500
```

### Windows

```bash
parte2.exe 2500
```

### Ejemplo de salida

```text
Initial head position: 2500
FCFS total movement: ...
SCAN total movement: ...
C-SCAN total movement: ...
```

---

# Ejecutar visualizacion.py

Este programa implementa nuevamente los algoritmos FCFS, SCAN y C-SCAN, pero además genera gráficas para visualizar:

- El recorrido del cabezal.
- Comparaciones de rendimiento entre algoritmos.

Utiliza la librería `matplotlib` para mostrar las gráficas.

## Ejecutar

### Linux / Mac

```bash
python3 visualizacion.py
```

### Windows

```bash
python visualizacion.py
```

---

# Explicación General

## parte2,2.cpp

- Genera 1000 solicitudes aleatorias de cilindros.
- Implementa:
  - FCFS
  - SCAN
  - C-SCAN
- Calcula el movimiento total del cabezal.
- Recibe la posición inicial del disco como parámetro.

---

## visualizacion.py

- Implementa los algoritmos:
  - FCFS
  - SCAN
  - C-SCAN
- Calcula el movimiento total del cabezal.
- Genera gráficas del recorrido del disco.
- Muestra una comparación visual entre algoritmos.

---


