/* manejo_argumentos.c */

#include <stdio.h>
#include <unistd.h>
#include <Windows.h>

int
main(int argc, char *argv[]) {

  extern char *optarg;
  extern int optind, opterr, optopt;
  int option;

  /* 
   * Verificando los argumentos
   */

  while ((option = getopt(argc, argv, "p:gc")) != -1) {

    switch (option) {
    case 'c':
      fprintf(stdout, "Entorno de consola activado\n");
      break;
            
    case 'g':
      fprintf(stdout, "Entorno gráfico activo\n");
      break;

    case 'p':
      fprintf(stdout, "Activada la impresora: %s\n", optarg);
      break;

    default:
      fprintf(stdout, "No se reconoce la opcion\n");
      break;
    }
  }

  return 0;
}
