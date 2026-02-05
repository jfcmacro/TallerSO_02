#include <windows.h>
#include <stdio.h>

#define SIZE_BUFFER 12

int
main() {
  HFILE hFile;
  char buffer[SIZE_BUFFER + 1];
  
  ZeroMemory(buffer, SIZE_BUFFER);
  
  hFile = OpenFile("../data/lope-de-vega-poema.txt", O_RDONLY);

  if (fd == -1) {
    fprintf(stderr, "Error abriendo archivo: %d\n", errno);
    _exit(1);
  }

  int tam;
  tam = read(fd, buffer, SIZE_BUFFER);

  if (tam == -1) {
    fprintf(stderr, "Error leyendo archivo: %d\n", errno);
    _exit(2);
  }

  buffer[tam] = '\0';
  while (tam != 0) {
    write(STDOUT_FILENO, buffer, tam);
    tam = read(fd, buffer, SIZE_BUFFER);

    if (tam == -1) {
      fprintf(stderr, "Error leyendo archivo: %d\n", errno);
      _exit(3);
    }
    buffer[tam] = '\0';
  }

  close(fd); // Cierra el archivo que se esta leyendo.
  _exit(0); // Termina 
}
