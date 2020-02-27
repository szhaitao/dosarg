#include "DosArg.h"
#include <stdio.h>

int argc;
/*const*/ char** argv;
//static 
const char* sNULL = "";

void initarg(const int c,/*const*/ char* v[])
{
	argc=c;
	argv=v;
} 
const char* getarg(const char* sname,const char* sdefault) //=sNULL)
{
	int i,l;
	char sn[128];
	l=strlen(sname);
	//strcpy(sn,name);
	//strcat(sn,"=");
	memcpy(sn,sname,l);
	sn[l]='=';
	++l;
	sn[l]=0;
	
	for (i=1; i<argc; i++)
		if (!strncmp(sn,argv[i],l))
		{
			return(argv[i]+l);
		}
	
	return(sdefault);
}
const char* getarg(const char* sname,const int len,const char* sdefault) //=sNULL)
{
	const char* p=getarg(sname,sdefault);
	if ((int)strlen(p)==len)
		return(p);
	return(sdefault);
}
void debugarg(void)
{
	for (int i=0; i<argc; i++) 
	{
		printf("Arg[%d]=>>%s<<\n",i,argv[i]);
	}
}
