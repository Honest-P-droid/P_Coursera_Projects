#ifndef STATS_H
#define STATS_H
/*@brief Prints various statistical values from given array of values.
       This function takes as input(s) the maximum, minimum, average, and median from seperate function outputs and displays all of them under one roof.
@param max The largest value from the given array of numbers/values.
       min The smallest value from the given array of numbers/values.
       avg The mean value from the given array of numbers/values.
       median The median value from the given array of numbers/values.
@return void*/
void print_statistics(int max, int min, float avg, float median);
/*@brief Sorts the given array.
       This function takes as inputs the given array's copy, and it's length, and gives the array sorted in ascending order as output.
@param data The pointer value, pointing to the array of unsigned char provided.
       len The length of the array.
@return void*/
void sort_array(unsigned char *data, int len);
/*@brief Prints the given array.
       This function takes as inputs the given array's data pointer and it's length.
@param data The pointer value, pointing to the array of unsigned char provided.
       len The length of the array.
@return void*/
void print_array(unsigned char *data, int len);
/*@brief Finds median of sorted dataset.
         This function takes as inputs the sorted dataset and it's length and finds it's median value. If the length is odd, median would be the center value; If even, median is the average of the 2 central values.
@param data The pointer value, pointing to the array of unsigned char provided.
       len The length of the array.
@return The median value of the given dataset, a float*/
float find_median(unsigned char *data, int len);
/*@brief Finds mean/average of given dataset.
 	 This function takes as input the given dataset and it's length and finds the average value or the mean.
@param data The pointer value, pointing to the array of unsigned char provided.
       len The length of the array.
@return The average/mean of the given dataset*/
float find_mean(unsigned char *data, int len);
/*@brief Finds the largest value in the given dataset.
 	 This function takes as input the given dataset and it's length and finds the largest value in it by comparing each succeding value.
@param data The pointer value, pointing to the array of unsigned char provided.
       len The length of the array.
@return The largest value of the given dataset*/
int find_maximum(unsigned char *data, int len);
/*@brief Finds the smallest value in the given dataset.
 	 This function takes as input the given dataset and it's length and finds the smallest value in it by comparing each succeding value.
@param data The pointer value, pointing to the array of unsigned char provided.
       len The length of the array.
@return The smallest value in the given dataset*/
int find_minimum(unsigned char *data, int len);

#endif
