



/**************************************************************
 *                                                            *
 *                     Done By: ApoAlquaary                   *
 *            Github: https://github.com/ApoAlquaary          *
 *                    Date: 15/11/2021                        *
 * 				   	 									                              *
 *************************************************************/



#ifndef HEADER_KAPSAK
#define HEADER_KAPSAK

typedef struct KANPSAK
{

	// the length of knapsak
	int len;
	// the points for every point
	int *points;
	// the weights for every point
	int *weights;
	// the posible solutions
	float *p_over_w;
	// the best solutions
	float *optimal_values;

	// function pointers
	int * (*__init__)(int x, struct KANPSAK *k);
	void (*SetPoints)(int arr[], struct KANPSAK *k);
	void (*CalcPOverW)(struct KANPSAK *knap);
	void (*SetWeights)(int arr[], struct KANPSAK *k);
	void (*ShowResults)(struct KANPSAK k);
	void (*CalcOptimal)(int m, struct KANPSAK *k);
	int (*Max)(int len, float arr[]);
} knapsak;



knapsak create_knapsak(int x);
void initialize(int x, knapsak *k);
void set_points(int arr[], knapsak *k);
void set_weights(int arr[], knapsak *k);
void calc_p_over_w(knapsak *k);
void calc_optimal(int m, knapsak *k);
int max(int len, float arr[]);
void show_result(knapsak k);

#endif
