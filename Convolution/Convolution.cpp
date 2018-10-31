void convolution(double **MatrixA, double **MatrixB, unsigned long StartRowA, unsigned long StartColA, unsigned long RowsB, unsigned long ColsB)
{
	unsigned long i, j;

	for (i = 0; i < RowsB; i++)
	{
		for (j = 0; j < ColsB; j++)
		{

			Sum = Sum + (MatrixA[StartRowA + i][StartColA + j] * MatrixB[i][j]);

		}
	}
} 