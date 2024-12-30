/* SYSC 2006 Lab 4. 

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "arrays.h"

/* Exercise 1. */

/* Return the average magnitude of the signal represented by
 * the n doubles in x[]. 
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], int n)
{
    double total = 0.0;

    for (int i = 0; i < n; i++){
        total += fabs(x[i]);
    }
    return (total/n);
}

/* Exercise 2. */

/* Return the average power of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], int n)
{
    double sum = 0.0;

    for (int i = 0; i < n; i++){
        sum += (double)pow(x[i], 2);
    }
    return (sum/n);
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double maxi(double arr[], int n)
{
    double maximum = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > maximum) {
            maximum = arr[i];
        }
    }
    return maximum;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double mini(double arr[], int n)
{
    double minimum = arr[0];

    for (int i = 1; i < n ; i++){
        if (arr[i] < minimum){
            minimum = arr[i];
        }
    }
    return minimum;
}

/* Exercise 5. */

/* Normalize the n doubles in x[]. 
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{

   /* double maximum = x[0];

    for (int i = 1; i < n; i++) {
        if (x[i] > maximum) {
            maximum = x[i];
        }
    double minimum = x[0];

    for (int i = 1; i < n ; i++){
        if (x[i] < minimum){
            minimum = x[i];
        }
     */
    double min_x = mini(x, n);
    double max_x = maxi(x, n);

    for (int i = 0; i < n ; i++){
        x[i] = (x[i] - min_x) / (max_x - min_x); 
    }


}
