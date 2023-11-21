#include "batcher.h"
#include "heap.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"

#include <stdint.h> //uint32_t32
#include <stdio.h>
#include <stdlib.h> //malloc, atoi
#include <unistd.h> //getopt().

#define OPTIONS "Hasbhqn:p:r:"

void print_sorted_array(
    Stats *stats, char *method, uint32_t *A, uint32_t n, uint32_t print_element) {
    printf("%s,", method);
    printf(" %d elements,", n);
    printf(" %lu moves,", stats->moves);
    printf(" %lu compares", stats->compares);

    //printing with formatting
    for (uint32_t i = 0; i < print_element; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("%12d ", A[i]);
    }
    printf("\n");
}

void copy_array(uint32_t *from, uint32_t *to, uint32_t n) {
    // holder = (uint32_t*)malloc(sizeof(uint32_t) * n);
    for (uint32_t i = 0; i < n; i++) {
        to[i] = from[i];
    }
}

int main(int argc, char **argv) {
    // Checks commandline arguments
    int opt = 0;
    uint32_t default_seed = 13371453; //Specify random seed (default: 13371453).
    uint32_t default_A_elements = 100; //Specify number of array elements (default: 100).
    uint32_t default_print = 100; //Specify number of elements to print (default: 100).

    //Create array for later sorting
    uint32_t *default_rand_array, *shell_array = NULL, *batcher_array = NULL, *heap_array = NULL,
                                  *quick_array = NULL;
    //Create defualt stats for each sorting methods. {0,0}
    Stats shell_stats, batcher_stats, heap_stats, quick_stats;

    //initiating set with set_empty()
    Set OPTIONS_set = set_empty();

    char *help_message
        = "SYNOPSIS\n   A collection of comparison-based sorting algorithms.\n\nUSAGE\n   "
          "./sorting [-Hasbhqn:p:r:] [-n length] [-p elements] [-r seed]\n\nOPTIONS\n -H           "
          "   Display program help and usage.\n -a              Enable all sorts.\n -s             "
          " Enable Shell Sort.\n -b              Enable Batcher Sort.\n -h              Enable "
          "Heap Sort.\n -q              Enable Quick Sort.\n -n length       Specify number of "
          "array elements (default: 100).\n -p elements     Specify number of elements to print "
          "(default: 100).\n -r seed         Specify random seed (default: 13371453).\n";
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'H': printf("%s", help_message); break;
        case 'a': OPTIONS_set = set_insert(OPTIONS_set, 'a'); break;
        case 's': OPTIONS_set = set_insert(OPTIONS_set, 's'); break;
        case 'b': OPTIONS_set = set_insert(OPTIONS_set, 'b'); break;
        case 'h': OPTIONS_set = set_insert(OPTIONS_set, 'h'); break;
        case 'q': OPTIONS_set = set_insert(OPTIONS_set, 'q'); break;
        case 'n': default_A_elements = atoi(optarg); break;
        case 'p': default_print = atoi(optarg); break;
        case 'r': default_seed = atoi(optarg); break;
        default: printf("invalid option\n");
        }
    }

    // no command then print help

    if (OPTIONS_set == set_empty()) {
        printf("%s", help_message);
    }

    //set the seed
    srandom(default_seed);

    if (default_print > default_A_elements) {
        default_print = default_A_elements;
    }

    default_rand_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
    for (uint32_t i = 0; i < default_A_elements; i++) {
        default_rand_array[i]
            = random() & (1 << 30) - 1; // Ben Grant left shift 30 bits - 1 (bit mask)
    }

    // print_sorted_array(Stats *stats, char *method, uint32_t *A, uint32_t n, uint32_t print_element)
    reset(&shell_stats); // set stats to {0,0}
    reset(&batcher_stats);
    reset(&heap_stats);
    reset(&quick_stats);

    if (set_member(OPTIONS_set, 'a')) {
        //-------------------------------shell
        shell_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
        copy_array(default_rand_array, shell_array, default_A_elements);
        // reset(&shell_stats);
        shell_sort(&shell_stats, shell_array, default_A_elements);
        print_sorted_array(
            &shell_stats, "Shell sort", shell_array, default_A_elements, default_print);
        //-------------------------------batcher
        batcher_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
        copy_array(default_rand_array, batcher_array, default_A_elements);
        // reset(&batcher_stats);
        batcher_sort(&batcher_stats, batcher_array, default_A_elements);
        print_sorted_array(
            &batcher_stats, "Batcher sort", batcher_array, default_A_elements, default_print);
        //-------------------------------heap
        heap_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
        copy_array(default_rand_array, heap_array, default_A_elements);
        // reset(&heap_stats);
        heap_sort(&heap_stats, heap_array, default_A_elements);
        print_sorted_array(&heap_stats, "Heap sort", heap_array, default_A_elements, default_print);
        //-------------------------------quick
        quick_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
        copy_array(default_rand_array, quick_array, default_A_elements);
        // reset(&quick_stats);
        quick_sort(&quick_stats, quick_array, default_A_elements);
        print_sorted_array(
            &quick_stats, "Quick sort", quick_array, default_A_elements, default_print);

    } else {
        if (set_member(OPTIONS_set, 's')) {
            shell_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
            copy_array(default_rand_array, shell_array, default_A_elements);
            // reset(&shell_stats);
            shell_sort(&shell_stats, shell_array, default_A_elements);
            print_sorted_array(
                &shell_stats, "Shell sort", shell_array, default_A_elements, default_print);
        }

        if (set_member(OPTIONS_set, 'b')) {
            batcher_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
            copy_array(default_rand_array, batcher_array, default_A_elements);
            // reset(&batcher_stats);
            batcher_sort(&batcher_stats, batcher_array, default_A_elements);
            print_sorted_array(
                &batcher_stats, "Batcher sort", batcher_array, default_A_elements, default_print);
        }

        if (set_member(OPTIONS_set, 'h')) {
            heap_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
            copy_array(default_rand_array, heap_array, default_A_elements);
            // reset(&heap_stats);
            heap_sort(&heap_stats, heap_array, default_A_elements);
            print_sorted_array(
                &heap_stats, "Heap sort", heap_array, default_A_elements, default_print);
        }

        if (set_member(OPTIONS_set, 'q')) {
            quick_array = (uint32_t *) malloc(sizeof(uint32_t) * default_A_elements);
            copy_array(default_rand_array, quick_array, default_A_elements);
            // reset(&quick_stats);
            quick_sort(&quick_stats, quick_array, default_A_elements);
            print_sorted_array(
                &quick_stats, "Quick sort", quick_array, default_A_elements, default_print);
        }
    }

    free(default_rand_array);
    free(shell_array);
    free(batcher_array);
    free(heap_array);
    free(quick_array);

    return 0;
}

// int main(void) {

//     srandom(13371453);

//     uint32_t default_A_elements = 5;
//     uint32_t default_print= 5;

//     uint32_t *default_rand_array = (uint32_t*)malloc(sizeof(uint32_t) * default_A_elements);
//     for (uint32_t i = 0; i < default_A_elements; i++) {
// 		default_rand_array[i] = random();
// 	}

// 	printf("rand array: ");
//     for (uint32_t  i = 0; i < default_A_elements; i++) {
//     printf("%d ", default_rand_array[i]);
//     }
//     printf("\n");

//     uint32_t *batcher_array = NULL;
//     create_copy_array(default_rand_array, batcher_array, default_A_elements);

//     printf("batcher array: ");
//     for (uint32_t  i = 0; i < default_A_elements; i++) {
//     printf("%d ", batcher_array[i]);
//     }
//     printf("\n");

//     printf("----------------1 batcher_sort 1--------\n");

//     Stats b_stats;

//     reset(&b_stats);

//     // Call the batcher_sort function
//     batcher_sort(&b_stats, batcher_array, default_A_elements);
//     printf("----------------2--------\n");

//     // Print the sorted array
//     print_sorted_array(&b_stats, "batcher sort", batcher_array, default_A_elements, default_print);

//     free(default_rand_array);
//     free(batcher_array);
//     // printf("Sorted array ori: ");
//     // for (uint32_t  i = 0; i < default_A_elements; i++) {
//     // printf("%d ", default_rand_array[i]);
//     // }
//     // printf("\n");

//     // Print the stats structure
//     // printf("Number of comparisons: %lu\n", b_stats.compares);
//     // printf("Number of moves: %lu\n", b_stats.moves);

//     return 0;
// }
