#include "stats.h"

#include <stdint.h> //uuint32_t32
#include <stdio.h>
#include <stdlib.h> //malloc

// void heap_sort(Stats *stats, uint32_t *A, uint32_t n);

uint32_t max_child(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    uint32_t left = 2 * first;
    uint32_t right = left + 1;
    if (right <= last && cmp(stats, A[right - 1], A[left - 1]) == 1) {
        return right;
    }
    return left;
}

void fix_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    uint32_t found = 0;
    uint32_t mother = first;
    uint32_t great = max_child(stats, A, mother, last);
    while (mother <= last / 2 && !found) {
        if (cmp(stats, A[mother - 1], A[great - 1]) == -1) {
            // uint32_t temp = A[mother - 1];
            // A[mother - 1] = A[great - 1];
            // A[great - 1] = temp;
            swap(stats, &A[mother - 1], &A[great - 1]);
            mother = great;
            great = max_child(stats, A, mother, last);
        } else {
            found = 1;
        }
    }
}

void build_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    for (uint32_t father = last / 2; father >= first; father--) {
        fix_heap(stats, A, father, last);
    }
}

void heap_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t first = 1;
    uint32_t last = n;
    build_heap(stats, A, first, last);
    for (uint32_t leaf = last; leaf >= first; leaf--) {
        // uint32_t temp = A[first - 1];
        // A[first - 1] = A[leaf - 1];
        // A[leaf - 1] = temp;
        swap(stats, &A[first - 1], &A[leaf - 1]);
        fix_heap(stats, A, first, leaf - 1);
    }
}

// int main(void) {
//     // uint32_t n = 5;
//     printf("started\n");
//     uint32_t A[5] = {3, 2, 5, 1, 4};
//     uint32_t n = sizeof(A) / sizeof(A[0]);
//     printf("----------------1 heap--------\n");

//     Stats stats = {0, 0};

//     // Call the batcher_sort function
//     heap_sort(&stats, A, n);
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

// def max_child ( A : list , first : uint32_t , last : uint32_t ) :
// 	left = 2 * first
// 	right = left + 1
// 	if right <= last and A [ right - 1] > A [ left - 1]:
// 		return right
// 	return left

// def fix_heap ( A : list , first : uint32_t , last : uint32_t ) :
// 	found = False
// 	mother = first
// 	great = max_child (A , mother , last )
// 	while mother <= last // 2 and not found :
// 		if A [ mother - 1] < A [ great - 1]:
// 			A [ mother - 1] , A [ great - 1] = A [ great - 1] , A [ mother - 1]
// 			mother = great
// 			great = max_child (A , mother , last )
// 		else :
// 			found = True

// def build_heap ( A : list , first : uint32_t , last : uint32_t ) :
// 	for father in range ( last // 2 , first - 1 , -1) :
// 		fix_heap (A , father , last )

// def heap_sort ( A : list ) :
// 	first = 1
// 	last = len ( A )
// 	build_heap (A , first , last )
// 	for leaf in range ( last , first , -1) :
// 		A [ first - 1] , A [ leaf - 1] = A [ leaf - 1] , A [ first - 1]
// 		fix_heap (A , first , leaf - 1)
