# SYSC 2006 - Lab 1 Solution template

__author__ = "Salma Khai"
__student_number__ = "101301357"

# Type your solution to exercise 1 after this line
def alarm_clock (day: int, vacation: bool) -> str:
    """Function takes an integer named day 
    which corresponds to a certain day of the week and
    it's vacation status but then returns a string
    containing the alarm time.

    Preconditions: 0 =< day and day =< 6

    Examples:

    alarm_clock (1, True):
    >>> 10:00

    alarm_clock (5, False):
    >>> 07:00

    alarm_clock (6, True):
    >>> off

    """
    if 1 <= day <= 5:
        if vacation == False:
            return ('07:00')
        elif vacation == True:
            return ('10:00')
    elif day == 0 or day == 6:
        if vacation == False:
            return ('10:00')
        elif vacation == True:
            return ('off')


# Type your solution to exercise 2 after this line

def count_replace() -> str:
    """Asks user for their input of a positive integer
    and the function counts from 1 until the entered number
    all while remplacing the multiples of 3 by 'Fizz' and multiples
    of 5 by 'Buzz'and multiples of both 3 and 5 by 'FizzBuzz'.

    Preconditions: User must enter a positive integer greater than 0.

    Examples:

    count_replace()
    Enter an integer number: <User enters 16>
    >>> 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16

    count_replace()
    Enter an integer number: <User enters 9>
    >>> 1 2 Fizz 4 Buzz Fizz 7 8 Fizz

    count_replace()
    Enter an integer number: <User enters 30>
    >>> 1 2 Fizz 4 Buzz Fizz 7 8 Fizz Buzz 11 Fizz 13 14 FizzBuzz 16 17 Fizz 19 Buzz Fizz 22 23 Fizz Buzz 26 Fizz 28 29 FizzBuzz

    """
    number = int(input("Enter an integer number (greater than zero): "))
    if number <= 0:
        print('Please enter a valid integer pertaining a value greater than 0')
        return
    
    for i in range(1, number + 1):
        if i % 3 == 0 and i % 5 == 0:
            print("FizzBuzz", end = ' ')
        elif i % 3 == 0:
            print("Fizz", end = ' ')
        elif i % 5 == 0:
            print("Buzz", end = ' ')
        else:
            print(i, end = " ")
        

# Type your solution to exercise 3 after this line

def is_prime(number: int) -> bool:
    """Function takes a positive integer and checks if
    the given number is a prime number returning the function as 
    True if it is.

    Preconditions: number > 0

    Examples:

    is_prime(1):
    >>> False

    is_prime(3):
    >>> True

    is_prime(9):
    >>> True
    """
    if number <= 1:
        return False

    for i in range(2, int(number**0.5) + 1):
        if number % i == 0:
            return False
    else:
        return True

# Type your solution to exercise 4 after this line

def divisors(numb: int) -> list:
    """Function takes in a positive integer as input and returns
    a list containing all its positive int divisors except if
    the input parameter is a zero the function returns
    and empty list.

    Preconditions: numb > 0

    Examples:

    divisors(6)
    >>> [1, 2, 3, 6]

    divisors(10)
    >>> [1, 2, 5, 10]

    divisors(33)
    >>> [1, 3, 11, 33]

    """

    dividers = []

    if numb == 0:
        return dividers

    if numb > 0:
        for i in range(1, numb + 1):
            if numb % i == 0:
                dividers += [i]
        return dividers