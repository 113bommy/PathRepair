from math import factorial
n = int(input())
if n<=2:
    print(1)
else:
    n -= 2
    print(2*(factorial(2*n)//(2*factorial(n)**2)))