/* polynomial.c - SYSC 2006 Lab 9 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "polynomial.h"

/* Print a polynomial term in the form ax^n; for example,
 * a term with coefficient 4 and exponent 5 is printed as 4x^5.
 */

void print_term(term_t *term) {
    if (term == NULL) {
        printf("Error: Null pointer received.\n");
        return;
    }
    printf("%dx^%d", term->coeff, term->exp);
    
    }

/* Make a polynomial term with coefficient coeff and exponent exp
 * and return the pointer to the term.
 *
 * Memory for the term is allocated from the heap.
 *
 * Terminate the program via assert if:
 * (1) coeff is 0;
 * (2) malloc fails.
 */
term_t *make_term(int coeff, int exp) { //if code does not work then change the names for coeff and exp
    assert(coeff != 0 && "Coefficient must not be zero.");

    // Allocate memory for a term_t struct
    term_t *new_term = (term_t *)malloc(sizeof(term_t));
    // Check if malloc succeeded
    assert(new_term != NULL && "Memory allocation failed for term_t.");

    // Initialize the struct
    new_term->coeff = coeff;
    new_term->exp = exp;

    return new_term;
}

/* Return the value of a polynomial term; i.e., return ax^n for a term with
 * coefficient a and exponent n when evaluated at x.
 * Example: if a term has coefficient 3 and exponent 2 and x is 4.0, 
 * this function returns 3(4.0^2), which is 48.0.
 */
double eval_term(term_t *term, double x) {
    // Check for a null pointer
    if (term == NULL) {
        fprintf(stderr, "Error: term is NULL.\n");
        return 0.0; // Return 0 for safety
    }

    // Calculate and return the value of ax^n
    return term->coeff * pow(x, term->exp);
}

/* Make a polynomial that has 0 terms and return the pointer to the polynomial. 
 * The polynomial can store up to MAX_TERMS terms (see polynomial.h).
 *
 * Memory for the polynomial is allocated from the heap.
 *
 * Terminate the program via assert if malloc fails.
 */

polynomial_t *make_polynomial(void) {
    // Allocate memory for the polynomial structure
    polynomial_t *poly = (polynomial_t *)malloc(sizeof(polynomial_t));
    
    // Assert that malloc was successful
    assert(poly != NULL);

    poly->num_terms = 0;

    return poly;
}

/* Add a term to a polynomial.
 *
 * This function doesn't check if the polynomial already contains a term with the
 * same exponent as the term being added; in other words, it's the caller's 
 * reponsibility to ensure that the polynomial doesn't have terms with duplicate 
 * exponents.
 *
 * Terminate the program via assert if there's no room in the polynomial for 
 * additional terms.
 */

void add_term(polynomial_t *poly, term_t *term) {
    // Assert that there is space for more terms in the polynomial
    assert(poly->num_terms < MAX_TERMS);

    // Add the new term to the polynomial's terms array
    poly->terms[poly->num_terms] = term;

    // Increment the number of terms in the polynomial
    poly->num_terms++;
}

/* Return the value of a polynomial when it is evaluated at x.
 *
 * Terminate the program via assert if the polynomial has 0 terms.
 */
double eval_polynomial(polynomial_t *poly, double x) {
    // Assert that the polynomial has at least one term
    assert(poly->num_terms > 0);

    double result = 0.0;

    // Evaluate each term in the polynomial
    for (int i = 0; i < poly->num_terms; i++) {
        result += eval_term(poly->terms[i], x);  // Evaluate and accumulate the term's value
    }

    return result;
}
