#include "stats.h"

#include <stdint.h> //uint32
#include <stdio.h>
#include <stdlib.h> //malloc

// void batcher_sort(Stats *stats, uint32_t *A, uint32_t n);

void comparator(Stats *stats, uint32_t *x, uint32_t *y) {
    // Compare two elements and swap them if x is greater than y
    if (cmp(stats, *x, *y) == 1) {
        swap(stats, x, y);
    }
}

void batcher_sort(Stats *stats, uint32_t *A, uint32_t n) {
    // If the array is empty or has only one element, return
    if (n == 0 || n == 1) {
        return;
    }

    uint32_t t = 0;
    // Calculate t, which is the log base 2 of n rounded up
    while ((1 << t) < n) {
        t++;
    }
    uint32_t p = 1 << (t - 1);

    // printf("n is %d, t is %d\n", n, t);

    while (p > 0) {
        uint32_t q = 1 << (t - 1);
        uint32_t r = 0;
        uint32_t d = p;

        while (d > 0) {
            for (uint32_t i = 0; i < n - d; i++) {
                if ((i & p) == r) {
                    comparator(stats, &A[i], &A[i + d]);
                }
            }
            d = q - p;
            q >>= 1;
            r = p;
        }
        p >>= 1;
    }
}

// 1 << n = 2^n

// int main(void) {
//     // uint32_t n = 5;
//     printf("started\n");
//     uint32_t A[5] = {3, 2, 5, 1, 4};
//     uint32_t n = sizeof(A) / sizeof(A[0]);
//     printf("----------------1 batcher_sort--------\n");

//     Stats stats = {0, 0};

//     // Call the batcher_sort function
//     batcher_sort(&stats, A, n);
//     printf("----------------2--------\n");

//     // Print the sorted array
//     printf("Sorted array: ");
//     for (uint32_t  i = 0; i < n; i++) {
//     printf("%d ", A[i]);
//     }
//     printf("\n");

//     // Print the stats structure
//     printf("Number of comparisons: %lu\n", stats.compares);
//     printf("Number of moves: %lu\n", stats.moves);

//     return 0;
// }

// int main(void) {
//     uint32_t A[] = {5, 7, 4, 6, 1};
//     uint32_t n = sizeof(A) / sizeof(A[0]);

//     Stats batcher_stats;

//     printf("n is %d, A is %d, A0 is %d\n", n, (uint32_t)sizeof(A), (uint32_t)sizeof(A[0]));

//     batcher_sort(&batcher_stats, A, n);

//     for (uint32_t i = 0; i < n; i++) {
//         printf("%d ", A[i]);
//     }
//     return 0;
// }

// def comparator ( A : list , x : int , y : int ):
// 	if A [ x ] > A [ y ]:
// 		A[x], A[y] = A[y], A[x]

// def batcher_sort ( A : list ) :
// 	if len ( A ) == 0:
// 		return

// 	n = len ( A )
// 	t = n.bit_length ()
// 	p = 1 << ( t - 1)

// 	while p > 0:
// 		q = 1 << ( t - 1)
// 		r = 0
// 		d = p

// 		while d > 0:
// 			for i in range (0 , n - d ):
// 				if ( i & p ) == r:
// 					comparator (A , i , i + d )
// 			d = q - p
// 			q > >= 1
// 			r = p
// 		p >>= 1
