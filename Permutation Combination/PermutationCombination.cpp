#include <iostream>

using namespace std;

void Permutate(char *string, bool *isVisited, int n, int r, char *result, int resultIndex)
{
	int i;

	if (r == 0)
	{
		for (i = 0; i < resultIndex; i++)
		{
			cout << result[i];
		}

		cout << endl;

		goto Exit;
	}

	for (i = 0; i < n; i++)
	{
		if (!isVisited[i])
		{
			isVisited[i] = true;

			result[resultIndex] = string[i];

			Permutate(string, isVisited, n, r - 1, result, resultIndex + 1);

			isVisited[i] = false;
		}
	}

Exit:

	return;
}

void Combination(char *string, int startIndex, int n, int r, char *result, int resultIndex)
{
	int i;

	if (r == 0)
	{
		for (i = 0; i < resultIndex; i++)
		{
			cout << result[i];
		}

		cout << endl;

		goto Exit;
	}

	for (i = startIndex; i < n; i++)
	{

		result[resultIndex] = string[i];

		Combination(string, i + 1, n, r - 1, result, resultIndex + 1);
	}

Exit:

	return;
}

int main()
{
	char key;

	char result[3];

	char string[] = "ABCD";

	bool isVisited[] = { false, false, false, false };

	printf("Permutation\n");

	Permutate(&string[0], &isVisited[0], 4, 3, &result[0], 0);

	printf("Combination\n");

	Combination(&string[0], 0, 4, 3, &result[0], 0);

	cout << "Press Any Key ";

	cin >> key;

	return 0;
}