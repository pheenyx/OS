/* ------------------------------------ */
/* Restklassen-Operationen              */
/* ------------------------------------ */
#include "include/rest_op.h"

int rest( int i )
{
	int k;
	k = i % BASIS;
	return k;
}

int rest_add( int i, int j )
{
	int k;
	k = (i + j) % BASIS;
	return k;
}

int basis( )
{
	return BASIS;
}
