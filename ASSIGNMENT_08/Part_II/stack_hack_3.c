#include <stdio.h>
#include <stdlib.h>

static long j = 200;

int testfunc(){
	int localarr[8000] = {5};
	int secondarr[9000] = {6};
	char x = printf("Hello World");
	return x;
}

int main() {
	
	testfunc();
	int i;
	printf("The stack top is near %p\n", &i);
        
	char *a = "Hello";	
	printf("The text segment is near %p\n", &a);

	printf("The data segment is near %p\n", &j);

	int *ptr;
	ptr=malloc(sizeof(int));
	printf("The heap segment is near %p\n", &ptr);

	return 0;
}
