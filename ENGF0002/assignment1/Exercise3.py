"""Fizzbuzz - Output numbers from 1 to 100. Multiple of
three will be replaced with fizz and multiple of five
will be replaced with buzz"""

for i in range(101):
    if i%3 == 0 and i%5 == 0:
        print("Fizzbuzz")
    elif i%3 == 0:
        print("Fizz")
    elif i%5 == 0:
        print("Buzz")
    else:
        print(str(i))