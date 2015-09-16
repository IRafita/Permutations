#include "libPerm.h"

void ShowVector (int s, int *e)
/* s size, e entrada */
{
	int i;
	for (i = 0; i < s; i++)
		printf ("%3d", e[i]);
	printf ("\n");
}

void MoveVectorLeft (int s, int p, int *e)
/*
 s size
 p posicio
 e entrada
*/
{
	int i, t = e[p];
	for (i = p; i < s -1; i++)
		e[i] = e[i+1];
	e[s-1] = t;
}

void NextPermutation (int s, int *e)
{
	int tM; /* token maxim */
	int tt; /* token temporal */
	int i = s -1; /* posicio en la que estem investigant */

	tM = e[i];
	tt = e[--i];

	while (tM < tt)
	{
		if (!--i)
		{
			printf ("No te element seguent\n");
			exit (0);
		}

		MoveVectorLeft (i, e);
		tM = tt;
		tt = e[i];
	}
	tt = e[i];
	e[i] = e[s-1];
	e[s-1] = tt;
}
