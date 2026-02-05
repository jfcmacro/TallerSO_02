# Taller 2

## Agenda

1. Preliminares
2. El mundo según C, C++ y otros
3. Llamadas al sistema
4. Estructura de directorios
5. Interpretador de comandos

## Preliminar

Abra una terminal. Abra el directorio de repositorio y de los talleres

```
cd <repositorio-enlace>
cd talleres
```

Descargue el taller en formato zip, descomprimalo.

```
wget https://github.com/jfcmacro/TallerSO_02/archive/refs/heads/master.zip
unzip master.zip
rm master.zip
```

Mire la estructura actual

```
tree .
```

Entre al directorio del taller

```
cd TallerSO_02-master
```

Adicione los ficheros

```bash
git add README.md .gitignore
```

Adicione los ficheros del proyecto, esto adiciona todos ficheros del taller.

```bash
find . -name *.c -exec git add {} \;
find . -name makefile -exec git add {} \;
```

Acometa (*commit*) el proyecto.

```
git commit -m "Iniciando el Taller 02"
git push
```

## El mundo según C, C++ y otros (Parte 2)

### Errores

Los errores surgen por diferentes razones, y los programas deben identificarla y manejarla según el contexto del programa. Usualmente, esto se maneja a través de las excepciones, en particular en el bloque `try`-`catch` (`try`-`except`). A diferencia de los lenguajes de programación, los sistemas operativos están basados en llamadas al sistema y estás retorna un código de error que debe ser entendido y manejado.

#### Mejoras al `makefile`

Observe al siguiente [`makefile`](./manejo-errores/linux/makefile).

* Manejo de dependencias (`$<`) y objetivos (`$@`).
* Variables predefinidas de compiladores: `${CC}`, `${CXX}`

#### Unix (Linux)

Gran parte de las llamadas al sistema utilizan hacen que la función devuelva en la información de estado no solamente una manija, sino también un código de error.

* [Generación de error](./manejo-errores/linux/error.c): Este programa como funciona la captura de errores.

Ir a la carpeta del taller:

```bash
cd <repositorio-enlace>
cd talleres/TallerSO_02-master/manejo-errores/linux
```

Compile:

```bash
make error
```

Ejecute:

```bash
./error
```

Esto muestra un código de error, investigue el código de error

```bash
errno 2
```

El comando `errno` permite ver el tipo de error, nos permite ver la información de todos los errores

```bash
errno -l
```

* [Obtener información de error](./manejo-errores/linux/obtener_error.c): Utiliza la función `perror` para identificar al error

Compile:

```bash
make obtener_error
```

Ejecute:

```bash
./obtener_error
```

* [Recuperar el error](./manejo-errores/linux/recuperar_errror.c): Una vez que ocurre un error este debe ser recuperador.

Compile:

```bash
make recuperar_error
```

Ejecute:

```bash
./recuperar_error
```

[**Ejercicio**] El programa anterior `recuperar_error.c` tiene un error en la concepción y es que este programa repite varia veces el mismo código, copie el programa con el nombre `recuperar_error_2.` de forma que no repita le mismo código a través de funciones.

#### Windows

Gran parte de las llamadas al sistema utilizan hacen que la función devuelva en la información de estado no solamente una manija, sino también un código de error.

* [Generación de error](./manejo-errores/windows/error.c): Este programa como funciona la captura de errores.

Ir a la carpeta del taller:

```bash
cd <repositorio-enlace>
cd talleres/TallerSO_02-master/manejo-errores/windows
```

Compile:

```bash
make error
```

Ejecute:

```bash
./error
```

Esto muestra un código de error, investigue el código de error. En la página de aprendizaje de [microsoft](https://learn.microsoft.com/en-us/windows/win32/debug/system-error-codes--0-499-). En la plataforma [Learn Microsoft](https://learn.microsoft.com/en-us/)

* [Obtener información de error](./manejo-errores/windows/obtener_error.c): Utiliza la función `perror` para identificar al error

Compile:

```bash
make obtener_error
```

Ejecute:

```bash
./obtener_error
```

## Llamadas al sistema

### Unix (Linux)

#### Conceptos

[Mostrar Poema con llamadas al sistema a través de `libc`](./llamadas-al-sistema/linux/mostrar_poema.c). Mostrar el contenido de un fichero, como lo hace el comando `cat`.

* Manual.
* Descriptores de ficheros (`fd`). Manijas.

[**Ejercicio**] A partir del [`mostrar_poema.c`](./llamadas-al-sistema/linux/mostrar_poema.c), crear un programa llamado `mostrar.c` que recibe a través de la línea de comando una lista de ficheros de texto, y mostrar cada uno de ellos.

Ejemplo: 

```bash
./mostrar fichero1.txt fichero2.txt fichero3.txt
```

La salida se vería así:

```bash
Contenido fichero 1
Contenido fichero 1
Contenido fichero 2
Contenido fichero 2
Contenido fichero 2
Contenido fichero 3
Contenido fichero 3
```

[Mostrar Poema con llamada al sistema directamente](./llamadas-al-sistema/linux/mostrar_poema_syscall.c). Mostrar el contenido de un fichero, como lo hace el comando `cat` con `syscall(2)`

* Parámetros variables

### Windows

#### Conceptos

[Mostrar Poema con llamadas al sistema del sub-entorno WinRT](./llamadas-al-sistema/windows/mostrar_poema.c). Mostrar el contenido de un fichero, como lo hace el comando `cat`.

* Manual.
* Manijas (`HANDLES`)

[**Ejercicio**] A partir del [`mostrar_poema.c`](./llamadas-al-sistema/windows/mostrar_poema.c), crear un programa llamado `mostrar.c` que recibe a través de la línea de comando una lista de ficheros de texto, y mostrar cada uno de ellos.

## Estructura de directorios

### Linux

![Estructura de directorios](./imagenes/image-20260204200857563.png)

### Windows

## Interpretador de comandos

### Comandos vistos en anteriormente

* `echo`
* `ls`
* `cat`
* `wc`

### Sistema de ayuda interactiva

* `man`
* [Man online](https://man7.org/linux/man-pages/)
* `zeal`
* [DevDocs](https://devdocs.io/)

### Directorio de trabajo

Abra una terminal. 

Ejecute el siguiente comando

```bash
pwd
```

Este comando muestra el directorio de trabajo actual.

Muestre el contenido del directorio

```bash
ls -la
```

Debe haber varios directorios especiales, en particular dos:  `.` directorio de actual, `..` padre

Cambie directorio al directorio padre.

```bash
cd ..
```

Mire la estructura de directorios.

```
tree .
```

Revise el manual `man tree` y pruebe varias opciones.

Mire el contenido del directorio con el comando `ls`. Revise el manual `man ls` y pruebe varias opciones.

Muévase al directorio de raíz:

```bash
cd /
```

Mire la estructura de directorios con `tree` y pruebe varias opciones.

Hay varias formas de volver al directorio del usuario: `cd $HOME`, `cd ~`, `cd`. 

### Manipulando ficheros

* `cp`: Copia un fichero a otro
* `mkdir`: Crea un directorio
* `mv`: Renombrar o mover un fichero
* `ln`: Enlazar un fichero
* `rmdir`: Borrar un directorio
* `rm`: Borrar un fichero

### Comandos básicos

*  `head`
* `cut`
* `grep`
* `sort`
* `uniq`
* 

### Ejecución de programa

* Estructura de la línea de comandos:
  * Comandos
  * Opciones
  * Argumentos
* Comandos
  * Programas. Todo ejecutable, con la ruta de camino o que se encuentre en la variable `$PATH` y que se tenga permisos, puede ser ejecutada
  * Ordenes internas
* Opciones
* Argumentos
  * Variables
  * Salida de otros programas como argumentos

### Información del estado del sistema

* `who`: 
* `ps`
* `top`

### Lenguaje de programación

