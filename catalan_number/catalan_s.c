#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "khash.h"

/* Define o tipo de hash: chave int -> valor int
KHASH_MAP_INIT_INT(mapa, long long)

khash_t(mapa) *hatoque;
khiter_t k;
int ret;*/

long long stair(int x) {
    if (x <= 0) return 1;

    /* Verifica se já está no cache
    k = kh_get(mapa, hatoque, x);
    if (k != kh_end(hatoque)) 
        return kh_value(hatoque, k);*/

    long long result = 0;
    for (int i = 0; i < x; ++i) {
        result += stair(i) * stair(x - 1 - i);
    }

    /* Insere no cache
    k = kh_put(mapa, hatoque, x, &ret);
    kh_value(hatoque, k) = result;*/

    return result;
}

int main(void) {
    //hatoque = kh_init(mapa);

    int N = 0;
    scanf("%d", &N);
    struct timespec start, end;
    long long elapsed;

    clock_gettime(CLOCK_MONOTONIC, &start);

    long long result = stair(N);

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = (end.tv_sec - start.tv_sec) * 1000000000LL 
            + (end.tv_nsec - start.tv_nsec);

    printf("stair(%d) = %lld\n", N, result);
    printf("Tempo decorrido: %lld ns\n", elapsed);

    //kh_destroy(mapa, hatoque);
    return 0;
}
