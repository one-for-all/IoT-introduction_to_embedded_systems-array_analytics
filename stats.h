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
 * @file stats.h
 * @brief Header file for stats.c
 *
 * Header file for a program that analyzes an array of numbers
 *
 * @author Lance Li
 * @date 09/18/17
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief print statistics of the array
 *
 * Print statistics including minimum, maximum, mean, and median.
 *
 * @param array An array of unsigned chars
 * @param size The number of elements in the array
 *
 * @return void
 */
void print_statistics(unsigned char *array, unsigned int size);

/**
 * @brief print the array
 *
 * Print the array
 *
 * @param array An array of unsigned chars
 * @param size The number of elements in the array
 *
 * @return void
 */
void print_array(unsigned char *array, unsigned int size);

/**
 * @brief returns the median of the array
 *
 * Compute and return the median of the array
 *
 * @param array An array of unsigned chars
 * @param size The number of elements in the array
 *
 * @return The median
 */
unsigned char find_median(unsigned char *array, unsigned int size);

/**
 * @brief returns the mean of the array
 *
 * Compute and return the mean of the array
 *
 * @param array An array of unsigned chars
 * @param size The number of elements in the array
 *
 * @return The mean
 */
unsigned char find_mean(unsigned char *array, unsigned int size);

/**
 * @brief returns the maximum of the array
 *
 * Compute and return the maximum of the array
 *
 * @param array An array of unsigned chars
 * @param size The number of elements in the array
 *
 * @return The maximum
 */
unsigned char find_maximum(unsigned char *array, unsigned int size);

/**
 * @brief returns the minimum of the array
 *
 * Compute and return the minimum of the array
 *
 * @param array An array of unsigned chars
 * @param size The number of elements in the array
 *
 * @return The minimum
 */
unsigned char find_minimum(unsigned char *array, unsigned int size);

/**
 * @brief sort the array in descending order
 *
 * Sort the array from largest to smallest in-place
 *
 * @param array An array of unsigned chars
 * @param size The number of elements in the array
 *
 * @return A sorted array
 */
unsigned char* sort_array(unsigned char *array, unsigned int size);

#endif /* __STATS_H__ */
