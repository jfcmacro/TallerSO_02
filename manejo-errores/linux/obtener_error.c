#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void
main(void) {
  int estado = open("../data/no-existe.txt", O_RDONLY);

  if (estado < 0) {
    perror("Error abriendo el fichero");
    exit(1);
  }

  exit(0);
}
