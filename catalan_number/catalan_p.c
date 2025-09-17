#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned long long stair(unsigned short x, unsigned long long int memo[]);

int main(void) 
{
	
    unsigned short N = 0;
    scanf("%hu", &N);
	
	unsigned long long int memo[N+1];
	
    struct timespec start, end;
    unsigned long long int elapsed;
	
	{
		for(register int i = 0; i <= N; ++i) memo[i] = -1;
	}
	memo[0] = 1;

    clock_gettime(CLOCK_MONOTONIC, &start);

    unsigned long long int result = stair(N, memo);

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = (end.tv_sec - start.tv_sec) * 1000000000LL 
            + (end.tv_nsec - start.tv_nsec);

    printf("stair(%d) = %lld\n", N, result);
    printf("Tempo decorrido: %lld ns\n", elapsed);

    return 0;
}

unsigned long long int stair(unsigned short n, unsigned long long int memo[]) {

    if(memo[n] != -1) 
        return memo[n];

    register unsigned long long int result = 0;

	for (register unsigned short i = 0; i <= (n - 1)/2 ; ++i)
	{
		result += stair(i, memo) * stair(n - 1 - i, memo);
	}

    result *= 2;

    if(n%2 != 0)
	    result -= stair((n-1)/2, memo)*stair((n-1)/2, memo);

    // Insere no cache
	memo[n] = result;

    return result;
}
