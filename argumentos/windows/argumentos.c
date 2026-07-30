/* argumentos.c
 *
 * Este programa se encarga de mostrar la lista de argumentos
 * pasados al programa.
 */
#include <stdio.h>
#include <Windows.h>

int
main(int argc, char *argv[]) {
  
  int i;

  fprintf(stdout, 
	  "Numero total de argumentos: %d\n", argc);

  /* Recorre cada uno de los argumentos y los 
   * muestra en la salida estandar */
  for (i = 0; i < argc; i++) {
    fprintf(stdout, "Argumento[%d]=%s\n", i, argv[i]);
  }

  return 0;
}
