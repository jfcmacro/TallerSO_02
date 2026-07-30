#include <stdio.h>
#include <Windows.h>

int
main(int argc, char *argv[]) {

  LPVOID lpvEnvironment;
  LPTSTR lpszVar;

  lpvEnvironment = GetEnvironmentStrings();

  if (lpvEnvironment) {

    for (lpszVar = lpvEnvironment;
	 *lpszVar;
	 lpszVar++) {

      while (*lpszVar)
	putchar(*lpszVar++);

      putchar('\n');
    }
  }

  FreeEnvironmentStrings(lpvEnvironment);
  
  return 0;
}
