#include<stdio.h>
#define cout(x) printf("\n %s",x)
#define NO_ERROR 0
#define MAX_STRING 255
#define ERROR_ES -1
#define es_digito(x) ((x >= '0' && x <= '9') ? 1 : 0)
#define es_blanco(x) ((x == ' ') ? 1 : 0)
#define a_decimal(x) (x - '0')
#define EOL '\n'

int main()
{
	char *p = "hello world";
	cout(p);

	return 0;
}