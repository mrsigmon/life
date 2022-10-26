//Compute sum of consecutive integers from 1 to N (inclusive)
//git will track everything else
#include <stdio.h>


long cumulative_sum(int N)
{
	long accumulator = 0;
	for (int n = 1; n <= N; n++) {
		accumulator = accumulator + n;
	}
	return accumulator;
		

}

