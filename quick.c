#include "stats.h"

#include <stdint.h> //uuuint32_t32_t32
#include <stdio.h>
#include <stdlib.h> //malloc

uint32_t partition(Stats *stats, uint32_t *A, uint32_t lo, uint32_t hi) {
    uint32_t i = lo - 1;
    for (uint32_t j = lo; j < hi; j++) {
        if (cmp(stats, A[j - 1], A[hi - 1]) == -1) {
            i += 1;
            // uint32_t temp = A[i - 1];
            // A[i - 1] = A[j - 1];
            // A[j - 1] = temp;
            swap(stats, &A[i - 1], &A[j - 1]);
        }
    }
    // uint32_t temp = A[i];
    // A[i] = A[hi - 1];
    // A[hi - 1] = temp;
    swap(stats, &A[i], &A[hi - 1]);

    return i + 1;
}

void quick_sorter(Stats *stats, uint32_t *A, uint32_t lo, uint32_t hi) {
    if (lo < hi) {
        uint32_t p = partition(stats, A, lo, hi);
        quick_sorter(stats, A, lo, p - 1);
        quick_sorter(stats, A, p + 1, hi);
    }
}

void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    quick_sorter(stats, A, 1, n);
}

// int main(void) {
//     // uint32_t n = 5;
//     printf("started\n");
//     uint32_t A[5] = {3, 2, 5, 1, 4};
//     uint32_t n = sizeof(A) / sizeof(A[0]);
//     printf("----------------1 quick--------\n");

//     Stats stats = {0, 0};

//     // Call the batcher_sort function
//     quick_sort(&stats, A, n);
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

// void quick_sort(Stats *stats, uint32_t *A, uint32_t n);

// def partition ( A : list , lo : uint32_t , hi : uint32_t ) :
// 	i = lo - 1
// 	for j in range (lo , hi) :
// 		if A [ j - 1] < A [ hi - 1]:
// 			i += 1
// 			A [ i - 1] , A [ j - 1] = A [ j - 1] , A [ i - 1]
// 	A [i], A[hi - 1] = A[hi - 1], A[i]
// 	return i + 1

// def quick_sorter(A : list , lo : uint32_t , hi : uint32_t):
// 	if lo < hi :
// 		p = partition (A , lo , hi)
// 		quick_sorter (A , lo , p - 1)
// 		quick_sorter (A , p + 1 , hi)

// def quick_sort (A : list) :
// 	quick_sorter (A, 1, len(A))
