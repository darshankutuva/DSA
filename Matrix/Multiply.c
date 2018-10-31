

bool
MultiplyMatrix(unsigned int M, unsigned int N, unsigned int P, unsigned int Q, unsigned int R, unsigned int S, int **Mat1, int **Mat2, int **ResMat)
{
	bool status = true;
	
	unsigned int i, j, k;
	
	if ((N != P) || (M != R) || (Q != S))
	{
		status = false;
		
		goto Exit;
	}
	
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < Q; j++)
		{
			sum = 0;
			
			for (k = 0; k < N; k++)
			{
				sum = sum + (Mat1[i][k] * Mat2[k][j]);
			}
			
			ResMat[i][j] = sum;
		}
	}
	
Exit:

	return status;
}