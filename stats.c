/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Print the statistics of the array
 *
 * Analyze the array and print its statistics including maximum, minimum, mean,
 * and median
 *
 * @author Lance Li
 * @date 09/18/17
 *
 */



#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

int main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  assert(find_maximum(test, SIZE) == 250);
  assert(find_minimum(test, SIZE) == 2);
  assert(find_mean(test, SIZE) == 93);
  unsigned char* sorted = sort_array(test, SIZE);
  unsigned char sorted_verify[SIZE] = {250, 244, 230, 201, 201, 200, 194, 190,
                                177, 154, 150, 123, 122, 114, 100,  99,
                                92,   90,  90,  88,  87,  87,  87,  76,
                                67,   60,  45,  34,  25,  23,  12,   8,
                                8,     7,   6,   6,   5,   3,   2, 2};
  for (int i = 0; i < SIZE; i++) {
    assert(sorted[i] == sorted_verify[i]);
  }
  assert(find_median(test, SIZE) == 87);
  unsigned char odd[3] = {1, 2, 3};
  assert(find_median(odd, 3) == 2);
  
  /* Statistics and Printing Functions Go Here */
  print_array(test, SIZE);
  print_statistics(test, SIZE);
}

void print_statistics(unsigned char *array, unsigned int size) {
  printf("Total number of elements: %d\n", size);
  printf("Mean: %d\n", find_mean(array, size));
  printf("Median: %d\n", find_median(array, size));
  printf("Maximum: %d\n", find_maximum(array, size));
  printf("Minimum: %d\n", find_minimum(array, size));
}

void print_array(unsigned char *array, unsigned int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

unsigned char find_median(unsigned char *array, unsigned int size) {
  unsigned char* sorted = sort_array(array, size);
  if (size == 0) {
    return 0;
  } else if (size%2 == 0) {
    unsigned int sum = sorted[size/2-1] + sorted[size/2];
    return sum/2;
  } else {
    return sorted[size/2];
  }
}

unsigned char find_mean(unsigned char *array, unsigned int size) {
  unsigned int total = 0;
  for (int i = 0; i < size; i++) {
    total += array[i];
  }
  return total/size;
}

unsigned char find_maximum(unsigned char *array, unsigned int size) {
  unsigned char max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *array, unsigned int size) {
  unsigned char min = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] < min) {
      min = array[i];
    }
  }
  return min;
}

/* Private helper function for sort_array */
unsigned char* copy_array(unsigned char *array, unsigned int size) {
  unsigned char* copy = malloc(size*sizeof(unsigned char));
  for (int i = 0; i < size; i++) {
    copy[i] = array[i];
  }
  return copy;
}

unsigned char* sort_array(unsigned char *array, unsigned int size) {
  unsigned char* copy = copy_array(array, size);
  for (int i = 0; i < size; i++) {
    for (int j = i+1; j < size; j++) {
      if (copy[j] > copy[i]) {
        unsigned char temp = copy[j];
        copy[j] = copy[i];
        copy[i] = temp;
       }
    }
  }
  return copy;
}
