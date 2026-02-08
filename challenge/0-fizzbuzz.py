#!/usr/bin/python3
"""
FizzBuzz implementation
"""
import sys

def fizzbuzz(n):
    """
    FizzBuzz function prints numbers from 1 to n separated by a space.
    - For multiples of three print "Fizz" instead of the number
    - For multiples of five print "Buzz"
    - For multiples of both three and five print "FizzBuzz"
    """
    if n < 1:
        return

    tmp_list = []
    for i in range(1, n + 1):
        # The check for both must come first
        if i % 3 == 0 and i % 5 == 0:
            tmp_list.append("FizzBuzz")
        elif i % 3 == 0:
            tmp_list.append("Fizz")
        elif i % 5 == 0:
            tmp_list.append("Buzz")
        else:
            tmp_list.append(str(i))
    print(" ".join(tmp_list))

if __name__ == '__main__':
    if len(sys.argv) <= 1:
        print("Missing argument")
        sys.exit(1)

    number = int(sys.argv[1])
    fizzbuzz(number)
