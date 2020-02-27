#if !defined(__DosArg__)
#define __DosArg__

//#include "..\photolib\vccximage\stdafx.h"
//#include "E:\\haitao\\163.com\\src\\photolib\\vcCxImage\\cximage\\demo2\\stdafx.h" //"..\photolib\vccximage\stdafx.h"

#include <string.h>

//#define sNULL ""
extern const char* sNULL; // = "";

extern void initarg(const int c,/*const*/ char* v[]);
extern const char* getarg(const char* sname,const char* sdefault=sNULL);
extern const char* getarg(const char* sname,const int len,const char* sdefault=sNULL);
extern void debugarg (void);

#ifdef debug
#define GetArg(var,def) var=(char* )getarg(#var,def);printf("%s=%s(%c)\n",#var,var,((var==def)?'*':' '))
#else
  #define GetArg(var,def) var=(char* )getarg(#var,def)
#endif //debug

#endif //__DosArg__
