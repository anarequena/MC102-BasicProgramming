  
int movimento(char C , int n, int acidente) 
  do {
      scanf ("%c", &C); /* le o caractere fornecido enquanto esse for diferente de '*' */
      if (braco == 0){ /* se o braço estiver vazio, o braço se move de acordo com os comandos */
	  if ((C == 'L') && ((n-1) >= 0)) /* o braço se move para a esquerda */
	    n = n - 1;
	  if ((C == 'R') && ((n+1) < X)) /* o braço se move para a direita */
	    n++;
	  if ((C == 'D') && (P[n] > 0)){ /* o braço pega uma caixa da posição correspondente */
	    P[n] = P[n] - 1;
	    braco++;
	  }
	} else if (braco == 1){ /* se o braço conter 1 caixa, o braço se move se nao cruzar com uma posição empilhada ao maximo */
	  if ((C == 'L') && ((n-1) >= 0)){ /* o braço se move para a esquerda se não ocorrer um acidente */
	    n = n - 1;
	    if (P[n] == Y)
	      acidente++;
	  }
	  if ((C == 'R') && ((n+1) < X)){ /* o braço se move para a direita se não ocorrer um acidente */
	    n++;
	    if (P[n] == Y)
	      acidente++;
	  }
	  if (C == 'D'){ /* o braço deixa a caixa na posição correspondente */
	    P[n] += 1;
	    braco = 0;
	  }
	}
	  
    } while ((C != '*') && !(acidente));