//SYSC 2006 - Lab 2 Template

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the necessary header for _Bool
#include "lab2.h"

/* Replace these lines with your information */ 
  const char* author_main = "Salma Khai"; 
  const char* student_number_main = "101301357"; 

int main(void){
  // Tests exercise 1 - Complete for a comprehensive test harness
  int expected_week_non_vac = 7;
  for(int day = 1; day <=5; day++){
    int alarm_time = alarm_clock(day, false);
    if (alarm_time == expected_week_non_vac) {
      printf("Day %d, Non vacation: TEST PASS.\n", day);
    } else {
      printf("Day %d, Non vacation: TEST FAIL.\n", day);
    }
  }
  int expected_week_vac = 10;
  for (int day = 1; day <=5; day++){
    int alarm_time = alarm_clock(day, true);
    if (alarm_time == expected_week_vac){
      printf("Day %d, Vacation: TEST PASS. \n", day);
    } else {
      printf("Day %d, Vacation: TEST FAL. \n", day);
    }
  }



  // Type your test cases for exercise 2. Make sure to include border line cases

  count_replace(16);
  count_replace(9);
  count_replace(30);

  // Type your test cases for exercise 3. Make sure to include border line cases

printf("\nis_prime(1));: %d", is_prime(1));
printf("\nis_prime(3));: %d", is_prime(3));
printf("\nis_prime(9));: %d", is_prime(9));
printf("\nis_prime(33));: %d", is_prime(33));
printf("\nis_prime(37));: %d", is_prime(37));




  // Type your test cases for exercise 4. Make sure to include border line cases

int expected_sum_1 = 30;
int sum1 = sum_even(10);
if (expected_sum_1 == sum1) {
  printf("TEST PASS\n");
}

int expected_sum_2 = 6;
int sum2 = sum_even(4);
if (expected_sum_2 == sum2) {
  printf("TEST PASS\n");
}

int expected_sum_3 = 12;
int sum3 = sum_even(6);
if (expected_sum_3 == sum3) {
  printf("TEST PASS\n");
}

printf("Test harness finished\n");
return EXIT_SUCCESS;
}


