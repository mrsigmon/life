#include <stdio.h>
#include <stdlib.h>

//char ga[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

char ga[26] = "abcdefghijklmnopqrstuvwxyz";

int one(char ca[]) {
	printf("function 1 %p %p %p\n",&ca, &ca[0], &ca[1]);
	}

int two(char *pa) {
	printf("function 2 %p %p %p %p\n", &pa, &pa[0], &pa[1],(++pa));
}


int main(){
	char ca[10];
	char *pa;
	one(ga);
	two(ga);

	printf("ga: %p %p %p\n", &ga, &ga[0], &ga[1]);
	return 0;
}

