#include <windows.h>
#include <stdio.h>

#define SIZE_BUFFER 12

int
main() {
  HANDLE hInFile;
  char buffer[SIZE_BUFFER + 1];
  
  ZeroMemory(buffer, SIZE_BUFFER);
  
  hInFile = CreateFileA("..\\data\\lope-de-vega-poema.txt",
			GENERIC_READ,
			FILE_SHARE_READ,
			NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL);

  if (hInFile == INVALID_HANDLE_VALUE) {
    fprintf(stderr, "Error abriendo archivo: %d\n", GetLastError());
    ExitProcess(1);
  }

  DWORD tam;
  if (!ReadFile(hInFile, buffer, SIZE_BUFFER, &tam, NULL)) {
    fprintf(stderr, "Error leyendo archivo: %d\n", GetLastError());
    ExitProcess(2);
  }

  buffer[tam] = '\0';
  HANDLE hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  
  while (tam != 0) {
    WriteFile(hOutputHandle, buffer, tam, NULL, NULL);
    if (!ReadFile(hInFile, buffer, SIZE_BUFFER, &tam, NULL)) {
      fprintf(stderr, "Error leyendo archivo: %d\n", errno);
      ExitProcess(3);
    }
    
    buffer[tam] = '\0';
  }

  CloseHandle(hOutputHandle); // Cierra el archivo que se esta escribiendo
  CloseHandle(hInFile);
  _exit(0); // Termina 
}
