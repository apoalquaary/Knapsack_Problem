


/**************************************************************
 *                                                            *
 *                     Done By: ApoAlquaary                   *
 *            Github: https://github.com/ApoAlquaary          *
 *                    Date: 15/11/2021                        *
 * 				   	 									                              *
 *************************************************************/


#include <stdio.h>
#include "knapsak.h"



int main(){

/**************************************************************
 *                                                            *
 *                          variables                         *
 *                                                            *
 *************************************************************/
    int mass = 15;
    int len = 7;
    int points[] = {10, 5, 15, 7, 6, 18, 3};
    int weights[] = {2, 3, 5, 7, 1, 4, 1};

/**************************************************************
 *                                                            *
 *                          functions                         *
 *                                                            *
 *************************************************************/

    knapsak knap;

    // create an object
    knap = create_knapsak(7);

    // set points within the object
    knap.SetPoints(points, &knap);

    // set weights within the object
    knap.SetWeights(weights, &knap);


    // calc the answers .. points over weights
    knap.CalcPOverW(&knap);


    // calculate optimal values
    knap.CalcOptimal(mass, &knap);

    // show results
    knap.ShowResults(knap);


    return 0;
}
