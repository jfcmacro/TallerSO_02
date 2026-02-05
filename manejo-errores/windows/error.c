#include <windows.h>
#include <stdio.h>

void
main(void) {
  OFSTRUCT openFileStruct;
  HFILE hFile = OpenFile("..\\data\\no-existe.txt", &openFileStruct, OF_READ);

  if (hFile == HFILE_ERROR) {
    fprintf(stderr, "Error abriendo fichero debido a %ld\n", GetLastError());
    ExitProcess(1);
  }

  exit(0);
}
