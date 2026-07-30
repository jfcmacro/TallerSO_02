/* variable.c - Windows */
#include <stdio.h>
#include <Windows.h>

int
main(int argc, char *argv[]) { 

  TCHAR buffer[256];

  if (GetEnvironmentVariable("VARIABLE",
			     buffer,
			     256)) {

    printf("VARIABLE=%s\n\r", buffer);
  }
  else {
    printf("VARIABLE no esta definida");
  }

  return 0;
}
