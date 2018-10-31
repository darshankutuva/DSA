
void Factorial(unsigned long N, unsigned long *Fact)
{
	unsigned long i;
	
	*Fact = 1;
	
	if (N == 0)
	{
		goto Exit;
	}
	
	for (i = N; i > 0; i--)
	{
		*Fact = *Fact * i;
	}
	
Exit:
	return;
}

bool Permutate(char *String,
			   unsigned long N,
			   unsigned long R,
			   char **Result)
{
	bool status = true;
	
	bool *IsVisited = NULL;
	
	unsigned long len;
	
	if (String == NULL || N == 0 || R == 0)
	{
		status = false;
		
		goto Exit;
	}
	
	len = strlen(String);
	
	IsVisited = new bool[len];
	
	if (IsVisited == NULL)
	{
		status = false;
		
		goto Exit;
	}
	
	memset(IsVisited, 0, len);
	
	PermutateRecursive(String, N, R, IsVisited, 0, Result);
	
Exit:

	if (IsVisited != NULL)
	{
		delete[] IsVisited;
	}

	return status;
	
}
void PermutateRecursive(char *String,
						unsigned long N, 
						unsigned long R,
						bool *IsVisited,
						unsigned long ResCol,
						char **Result)
{
	unsigned long i;
	
	static unsigned long ResRow;

	if (R == 0)
	{
		Result[ResRow][ResCol] = '\0';

		ResRow++;
		
		goto Exit;
	}

	for (i = 0; i < N; i++)
	{
		if (!IsVisited[i])
		{
			IsVisited[i] = true;

			Result[ResRow][ResCol] = String[i];

			PermutateRecursive(String, IsVisited, N, R - 1, Result, ResCol + 1);

			IsVisited[i] = false;
		}
	}

Exit:

	return;
}



int
main()
{
	char string = "ABCD";

	char **result = NULL;
	
	unsigned long len, i, j numPermuatations;
	
	len = strlen(string);

	printf("Permutation\n");
	
	for (i = 1; i < len; i++)
	{
		numPermutations = Factorial(len) / Factorial(len - index);
		
		result = new char*[numPermutations];
		
		if (result == NULL)
		{
			goto Exit;
		}
		
		for (j = 0; j < numPermutations; j++)
		{
			result[j] = new char*[len + 1];
			
			if (result[j] == NULL)
			{
				goto Exit;
			}
		}
		
		Permutate(string, isVisited, len, index, &result[0][0], 0);
		
		for (j = 0; j < numPermutations; j++)
		{
			delete[] result[j];
		}
			
		delete[] result;
	}
	
Exit:
	if (result != NULL)
	{
		for (j = 0; j < numPermutations; j++)
		{
			if (result[j] != NULL)
			{
				delete[] result[j];
			}
		}
		
		delete[] result;
	}
	
	return 0;
}