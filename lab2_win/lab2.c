//SYSC 2006 - Lab 2 Solution template

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the necessary header for _Bool
#include <math.h>
#include "lab2.h"

/* Replace these lines with your information */ 
  const char* author = "Salma Khai"; 
  const char* student_number = "101301357"; 

// Type your solution to exercise 1 inside the body of the function. You need to update the return statement
int alarm_clock(int day,_Bool vacation) {
  if (1 <= day && day <= 5 ) {
    if (vacation == false) {
      return 7;
    } else {
      return 10;
    } 
  } if (day == 0 || day == 6) {
      if (vacation == false) {
        return 10;
      } else {
        return -1;
      }
    }
}
// Type your solution to exercise 2 inside the body of the function.
void count_replace(int value) {
  for (int i = 1; i <= value; i++ ) {
    if (i % 3 == 0 && i % 5 == 0){
      printf("Fizzbuzz ");
    } else if (i % 3 == 0) {
      printf("Fizz ");
    } else if (i % 5 == 0) {
      printf("Buzz ");
    } else {
      printf("%d ", i);
    }
  }
  printf("\n");

  return;
}
// Type your solution to exercise 3 inside the body of the function. You need to update the return statement
_Bool is_prime(int value){

  if (value <= 1) {
    return false;
  }
  for (int i = 2; i < value; i++) {
    if (value % i == 0){
      return false;
    }
  }
  return true;
}

// Type your solution to exercise 4 inside the body of the function. You need to update the return statement

int sum_even(int value){

  int sum = 0;
  for (int i = 1; i <= value; i++){
    if (i % 2 == 0) {
      sum += i;
    }
  }
  return sum;
}