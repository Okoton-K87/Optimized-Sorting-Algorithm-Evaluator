#include "gaps.h"
#include "stats.h"

#include <stdint.h> //uint32
#include <stdio.h>
#include <stdlib.h> //malloc

void shell_sort(Stats *stats, uint32_t *arr, uint32_t length) {
    uint32_t gap_length = sizeof(gaps) / sizeof(gaps[0]);
    uint32_t gap, k, i, j, temp;
    for (k = 0; k < gap_length; k++) {
        gap = gaps[k];
        for (i = gap; i < length; i++) {
            j = i;
            temp = move(stats, arr[i]);
            while (j >= gap && cmp(stats, temp, arr[j - gap]) == -1) {
                arr[j] = move(stats, arr[j - gap]);
                j -= gap;
            }
            arr[j] = move(stats, temp);
        }
    }
}

// int main(void) {
//     // uint32_t n = 5;
//     printf("started\n");
//     uint32_t A[5] = {3, 2, 5, 1, 4};
//     uint32_t n = sizeof(A) / sizeof(A[0]);
//     printf("----------------1 shell--------\n");

//     Stats stats = {0, 0};

//     // Call the batcher_sort function
//     shell_sort(&stats, A, n);
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

// void shell_sort (int arr[], int n, int gaps[], int m) {
//   int gap, i, j, temp;

//   for (int k = 0; k < m; k++) {
//     gap = gaps[k];
//     for (i = gap; i < n; i++) {
//       temp = arr[i];
//       j = i;
//       while (j >= gap && temp < arr[j - gap]) {
//         arr[j] = arr[j - gap];
//         j -= gap;
//       }
//       arr[j] = temp;
//     }
//   }
// }

// def shell_sort ( arr ) :
// 	for gap in gaps :
// 		for i in range ( gap , len ( arr ) ) :
// 			j = i
// 			temp = arr [ i ]
// 			while j >= gap and temp < arr [ j - gap ]:
// 				arr [ j ] = arr [ j - gap ]
// 				j -= gap
// 			arr [ j ] = temp
