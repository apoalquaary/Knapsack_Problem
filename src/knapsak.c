


/**************************************************************
 *                                                            *
 *                     Done By: ApoAlquaary                   *
 *            Github: https://github.com/ApoAlquaary          *
 *                    Date: 15/11/2021                        *
 * 				   	 									                              *
 *************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "knapsak.h"

knapsak create_knapsak(int len){
	knapsak this;
	this.len = len;
	this.__init__ = (void*)initialize;
	this.SetPoints = set_points;
	this.CalcPOverW = calc_p_over_w;
	this.SetWeights = set_weights;
	this.CalcOptimal = calc_optimal;
	this.ShowResults = show_result;
	this.Max = max;
	this.__init__(len, &this);
	return this;
}


void initialize(int len, knapsak *knap){

	knap->points = (int *)malloc(sizeof(int)* len);
	knap->weights = (int *)malloc(sizeof(int)* len);
	knap->p_over_w = (float *)malloc(sizeof(float)* len);
	knap->optimal_values = (float *)malloc(sizeof(float)* len);

	int i=0;
	for(i=0;i<len;i++){
		knap->points[i] = 0;
		knap->weights[i] = 0;
		knap->p_over_w[i] = 0;
		knap->optimal_values[i] = 0;
	}

}


void set_points(int arr[], knapsak *knap){

	int i = 0;
	for(i =0;i<knap->len;i++){
		knap->points[i] = arr[i];
	}
}
void set_weights(int arr[], knapsak *knap){

	int i = 0;
	for(i =0;i<knap->len;i++){
		knap->weights[i] = arr[i];
	}
}

void calc_p_over_w(knapsak *knap){

	int i = 0;
	for(i =0;i<knap->len;i++){
		knap->p_over_w[i] = (float) knap->points[i] / (float) knap->weights[i];
	}

}

void calc_optimal(int m, knapsak* knap){
	float mass = (float)m;

	float p_over_w[knap->len];
	int i;
	for (int i = 0; i < knap->len; i++)
	{
		p_over_w[i] = knap->p_over_w[i];
	}

	while(mass > 0){

		int index = max(knap->len, p_over_w);

		if(mass - knap->weights[index] >= 0){
			knap->optimal_values[index] = 1;

		}else{
			mass /= knap->weights[index];
			knap->optimal_values[index] = mass;
			mass = -1;
		}
		mass -= knap->weights[index];
		p_over_w[index] = 0;

	}
}

int max(int len, float arr[]){
	int index = 0;
	float MAX = arr[0];
	int i=0;

	for(i;i<len;i++){
		if(MAX<arr[i]){
			MAX = arr[i];
			index = i;
		}
	}

	return index;
}



void show_result(knapsak knap){

	printf("Objects:\t\t");
	for (int i = 0; i < knap.len; i++)
	{
		printf("(%d)\t", i+1);
	}
	printf("\n");
	printf("Points:\t\t\t");
	for (int i = 0; i < knap.len; i++)
	{
		printf("(%d)\t", knap.points[i]);
	}
	printf("\n");
	printf("Weights:\t\t");
	for (int i = 0; i < knap.len; i++)
	{
		printf("(%d)\t", knap.weights[i]);
	}
	printf("\n");
	printf("Solutions:\t\t");
	for (int i = 0; i < knap.len; i++)
	{
		printf("(%.2f)\t", knap.p_over_w[i]);
	}
	printf("\n");
	printf("Optimal values:\t\t");
	for (int i = 0; i < knap.len; i++)
	{
		printf("(%.2f)\t", knap.optimal_values[i]);
	}

	float sum;
	for (int i = 0; i < knap.len; i++)
	{
		sum += knap.optimal_values[i] * knap.points[i];
	}
	printf("\n\n");
	printf("The optimal values to take 15KG is (%.2f)", sum);
	printf("\n\n");

}
