// Use command "top -i" to see this process with %CPU usage
// This usage can be increased by giving a larger value of n
// (starting value) or decreased with a larger value of ud (delay)
// Change these two values until a nice round number is reached
// (10%, 50%, 100%, etc.) and record the timer's performance
//
// Compile with "gcc prime.c -o prime" and execute with
// "./prime <n value> <ud value>"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int prime(int n, int ud) {
	int i;
	int prime = 1;

	for(i = 2; i < n; i++) {
		if((n % i) == 0) {
			prime = 0;
		}
	}

	if(prime == 1) printf("%d\n", n);
	usleep(ud);
	return 0;
}


int main(int argc, char *argv[]) {
	int i = atoi(argv[1]);

	while(1) {
		prime(i, atoi(argv[2]));
		i++;
	}
}
