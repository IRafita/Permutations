
void MouElementDreta (int p, int *e)
/* p es la posicio on se vol moure tot */
{
	int t = e[p];
	e[p] = e[p-1];
	while (--p)
		e[p] = e[p-1];
	e[0] = t;
}

/* Nomes necessita reordenar el que entrem */
void ParserPermutationDigitToVector (int d, int s, int *e)
/*
 d digit que se vol transformar
 s tamany d'e
 e es la entrada que se transformara en sortida
*/
{
	int p; /* un punter */
	int i = s; /* digits que falten per trobar */

	while (d)
	{
		/* estan parlant molt fort, no me consentro per a res. ja ho farem en un futur proxim */

		p = d/i;
		d %= i--;

		MouElementDreta (p, e);
	}
}
