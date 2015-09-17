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
int
/*
	necessari per a poder acabar el programa quan toca
	0 correcte
	1 final, no te sentit buscar el seguent quan ja no n'hi ha
	2 resultat sense sentit ;-)
*/
NextPermutationV2 (int s, int *v)
{
	int i, j, tt, tM;

	i = s-1;
	tM = v[i];

	while (i--)
	{
		tt = v[i];
		if (tt < tM)
		{
			for (j = i +1; j < s; j++)
			{
				tM = v[j];
				if (tt < tM)
				{
					v[i] = v[j];
					v[j] = tt;
					return 0; /* tot correcte */
				}
			}
			return 2; /* si entres al condicional ja estas teoricament al final i esta assegurat */
		} else
		{
			tM = tt;
			MoveVectorLeft (s, i, v);
		}
	}
return 1;
}


/****************************************************************************************************************************************************/
/******************                               Ara vaig per aqui, tota la resta es recuperat de next                           *******************/
/****************************************************************************************************************************************************/
int /* Retona el calor que ha calculat que es */
CalcPermutations (int s, int *e)
/*
 s size
 e vector ordenat amb tots els elements
*/
{
	int tv, repe = 1, i, o = 1;

	tv = e[0];
	for (i = 1; i < s; i++)
	{
		if (tv = e[i])
		{ /* cas de repeticio */
			repe++;

			o *= i +1;
			o /= repe;
		} else
		{
			repe = 1;

			o *= i +1;
		}
	}
return o;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int * /* retorna el vector en si */
CopyShortVector (int s, int *e)
{
	int *o, i;

	o = malloc (s * sizeof (int));
	if (!o)
	{
		printf ("No vol reservar la memoria demanada. Big problem to CopyShortVector\n\n");
		exit (1);
	}
	for (i = 0; i < s; i++)
		o[i] = e[i];
	qsort (o, s, sizeof (int), cmpfunc);
return o;
}

int /* Retorna el valor que ha calculat ser */
ParserVectorDigit (int s, int *e)
{
	int i, o = 0;

	/* posiblitat * busqueda/ total */

	/* pupa cap, ara no tic pel que haura d'estar, aixi que ja ni se parlrar , llavors rrr aaa rrr mmm deu */
	int * vS;
	int possiblitat, nelements;

	vS = CopyShortVector (s, e);
	nelements = s;
	possiblitat = CalcPermutations (s, vS);

free (e);
return o;
}
