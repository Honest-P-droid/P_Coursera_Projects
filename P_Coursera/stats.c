/**/
#include <stdio.h>
#include "stats.h"
int main(){
	unsigned char dataset[]={19,54,67,23,45,
							 78,91,23,56,90,
							 23,45,67,85,43,
							 22,46,77,92,54};
	unsigned char datasetcpy[]={19,54,67,23,45,
								78,91,23,56,90,
								23,45,67,85,43,
								22,46,77,92,54};
	int len = sizeof(dataset)/sizeof(dataset[0]);
	printf("Array elements:\n");
	print_array(dataset, len);
	printf("Sorted Array:\n");
	sort_array(datasetcpy, len);
	print_array(datasetcpy, len);
	unsigned char max = find_maximum(dataset, len);
	unsigned char min = find_minimum(dataset, len);
	float median = find_median(datasetcpy, len);
	float avg = find_mean(dataset, len);
	print_statistics(max, min, avg, median);
}

void print_array(unsigned char *data, int len){
	for(int i=0; i<len; i++){
		printf("%d ", data[i]);
	}
	printf("\n");
}

int find_maximum(unsigned char *data, int len){
	int max_asp = data[0];
	for(int i=0; i<len; i++){
		if(data[i]>max_asp){
			max_asp = data[i];
		}
	}
	return(max_asp);
}

int find_minimum(unsigned char *data, int len){
	int min_asp = data[0];
	for(int i=0; i<len; i++){
		if(data[i]<min_asp){
			min_asp = data[i];
		}
	}
	return(min_asp);
}

float find_mean(unsigned char *data, int len){
	int sigma = 0;
	for(int i=0; i<len; i++){
		sigma += data[i];
	}

	return ((float)sigma/len);
}

float find_median(unsigned char *data, int len){
	if(len%2==0){
		float midterm=data[len/2]+data[(len-2)/2];
		return(midterm/2);
	}
	else{
		return(data[(len-1)/2]);
	}
}

void sort_array(unsigned char *data,int len){
	for(int i=1; i<len; i++){
		int key = data[i];
		int j = i-1;
	while(j>=0 && data[j]<key){
		data[j+1] = data[j];
		j--;
	}
	data[j+1] = key;
	}
}

void print_statistics(unsigned char max, unsigned char min, float avg, float median){
	printf("Maximum value:%d\n", max);
	printf("Minimum value:%d\n", min);
	printf("Mean value:%.2f\n", avg);
	printf("Median value:%.2f\n", median);
}
