#include <windows.h>
#include <stdio.h>

void
main(void) {
  HANDLE hFile = CreateFileA("..\\data\\no-existe.txt",
			     GENERIC_READ,
			     FILE_SHARE_READ,
			     NULL,
			     OPEN_EXISTING,
			     FILE_ATTRIBUTE_NORMAL,
			     NULL);

  if (hFile == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "Error abriendo fichero debido a %ld\n", GetLastError());
    ExitProcess(1);
  }

  ExitProcess(0);
}
