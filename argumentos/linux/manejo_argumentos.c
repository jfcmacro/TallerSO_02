/* ManejoDeArgumentos.c */

#include <stdio.h>
#include <unistd.h>

void uso(const char* progname, int valor_retorno);

int
main(int argc, char *argv[]) {

  extern char *optarg;
  extern int optind, opterr, optopt;
  int option;

  /* 
   * Verificando los argumentos
   */

  while ((option = getopt(argc, argv, ":cghp:")) != -1) {

    switch (option) {      
    case 'c':
      fprintf(stdout, "Entorno de consola activado\n");
      break;

    case 'h':
      uso(argv[0], 0);
      break;
      
    case 'g':
      fprintf(stdout, "Entorno GUI activo\n");
      break;
      
    case 'p':
      fprintf(stdout, "Activada la impresora: %s\n", optarg);
      break;

    case '?':
    default:
      uso(argv[0], 1);
      break;
    }
  }

  return 0;
}

void uso(const char* nombre_programa, int valor_retorno) {
  fprintf(stdout, "Uso: %s -h\n", nombre_programa);
  fprintf(stdout, "     %s [-c] [-g] [-p <nombre_impresora>]\n", nombre_programa);
  _exit(valor_retorno);
}
