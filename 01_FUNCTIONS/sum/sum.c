//Compute sum of consecutive integers from 1 to N (inclusive)
//git will track everything else
#include <stdio.h>

long cumulative_sum(int N);

int main(int argc, char *argv[])
{
	//Ask for number
	int N;
	long result;

	printf("Enter a number:\n");
	scanf("%d", &N); //%d
	//Computer number
	result = cumulative_sum(N);
	//Retunr number
	printf("The sum from 1 to %d (inclusive) is %ld\n", N, result);
	return 0;
}

long cumulative_sum(int N)
{
	long accumulator = 0;
	for (int n = 1; n <= N; n++) {
		accumulator = accumulator + n;
	}
	return accumulator;
		

}

