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
	//Return number
	printf("The sum from 1 to %d (inclusive) is %ld\n", N, result);
	return 0;
}

long cumulative_sum(int N)
{
	long accumulator;

	if (N==1) 
		accumulator = 1;
	else
		accumulator = N + cumulative_sum(N-1);
	return accumulator;
}

