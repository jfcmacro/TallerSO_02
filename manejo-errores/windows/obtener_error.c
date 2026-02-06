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

    DWORD dwError = GetLastError();
    HLOCAL hlocal = NULL;
    DWORD systemLocale = MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL);

    BOOL fOK = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dwError,
        systemLocale,
        (PTSTR) &hlocal,
        0,
	NULL);
    if (fOK) {
      fprintf(stderr, "%s\n", hlocal);
      LocalFree(hlocal);
    }
    else {
      fprintf(stderr,
	      "Error abriendo fichero debido a %ld\n",
	      GetLastError());
      ExitProcess(1);
    }
    
    ExitProcess(1);
  }
}
