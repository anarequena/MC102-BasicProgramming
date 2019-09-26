else if (braco = 'G'){
	  /* se o caractere for G, executa os comandos do caractere seguinte */
	  if (programa[n-1][j] == 'G'){
	    /* se o caractere for L, movimenta o braco para a esquerda da matriz posicao */
	    if (programa[n-1][j+1] == 'L'){
	       if (posicao[pl][pc-1] == '.')
		pc = left(pc);
	      else 
		acidente++;
	    }
	    /* se o caractere for R, movimenta o braco para a direita da matriz posicao */
	    if (programa[n-1][j+1] == 'R'){
	      if (posicao[pl][pc+1] == '.')
		pc = right(pc);
	      else 
		acidente++;
	    }
	    /* se o caractere for D, movimento o braco para baixo até encontrar uma caixa */
	    if (programa[n-1][j] == 'D'){
	      while (posicao[pl][pc]=='.')
		pl++;
	      posicao[pl-1][pc] = braco;
	      braco = '0';
	      pl = 0;
	    }
	    j = j + 2;
	  }
	