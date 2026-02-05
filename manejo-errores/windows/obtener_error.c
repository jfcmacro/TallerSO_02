#include <windows.h>
#include <stdio.h>

void
main(void) {
  OFSTRUCT openFileStruct;
  HFILE hFile = OpenFile("..\\data\\no-existe.txt",
			 &openFileStruct, OF_READ);

  if (hFile == HFILE_ERROR) {
    DWORD dw = GetLastError();
    LPVOID lpMsgBuf;
    if (FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | 
        FORMAT_MESSAGE_FROM_SYSTEM |
        FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        dw,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR) &lpMsgBuf,
        0, NULL) == 0) {
      fprintf(stderr, "%s\n", lpMsgBuf);
      LocalFree(lpMsgBuf);
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
