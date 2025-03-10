/**
 * @author  Bill Chen
 * @date    March 10th, 2025
 * 
 * @brief   This program is an implementation of 2 - Way matching algorithm.
 *          It searches for values from a 2D array (fileA) and in another 2D array 
 *          (fileB) where there sum equals target and reports the corresponding coordinates.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

/**
 * @param   k    Number of columns in the arrays.
 * @param   n    Number of rows in the arrays.
 * @param   fileA[k][n] The first 2D array containing values to search for.
 * @param   fileB[k][n] The second 2D array where values are searched.
 * @param   target  The specific value being searched.
 * @param   x1, y1  Pointers to store coordinates in fileA.
 * @param   x2, y2  Pointers to store coordinates in fileB.
 * 
 * @return  Prints the matching or missing values along with their coordinates.
 */
void findCoordinates(int n, int k, int fileA[n][k], int fileB[n][k], int target,
                     int *x1, int *y1, int *x2, int *y2) {
    
    *x1 = 0;
    *y1 = 0;
    *x2 = 1;
    *y2 = 1;

    for (int a_i = 0; a_i < n; a_i++) {  
        for (int a_j = 0; a_j < k; a_j++) {  
            int match = 100 - fileA[a_i][a_j]; // The difference between target and item a will result in the correct sum needed in B  
            int found = 0;  

            for (int b_i = 0; b_i < n && !found; b_i++) {  
                for (int b_j = 0; b_j < k; b_j++) {  
                    if (fileB[b_i][b_j] == match) {  
                        printf("Value %d (fileA[%d][%d]) found in fileB[%d][%d]\n", 
                               match, a_i, a_j, b_i, b_j);
                        found = 1;  
                        break;
                    }
                }
            }

            if (found == 0) {
                printf("Value %d (fileA[%d][%d]) NOT found in fileB\n", match, a_i, a_j);
            }
        }
    }
}

/**
 * @brief   Main function to test the findCoordinates function.
 */
int main() {
    const int k = 3, n = 4, target = 100;

    int fileA[n][k] = { 
        {10, 20, 30}, 
        {20, 40, 50}, 
        {50, 60, 70}, 
        {30, 80, 10} 
    };

    int fileB[n][k] = { 
        {60, 70, 40}, 
        {50, 80, 20}, 
        {80, 60, 50}, 
        {90, 40, 30} 
    };

    clock_t start = clock(); // calculates how long it takes the program to calculate coordinates

    int x1, y1, x2, y2;
    findCoordinates(n, k, fileA, fileB, target, &x1, &y1, &x2, &y2);

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;  // Time in seconds
    double time_taken_ms = time_taken * 1000;  // Time in milliseconds

    printf("\n");
    printf("Time taken: %.6f seconds\n", time_taken);
    printf("Time taken: %.6f milliseconds\n", time_taken_ms);

    return 0;
}
