def factorial(num):
    """This is a recursive function that calls
   itself to find the factorial of given number"""
    if num == 1:
        return num
    else:
        return num * factorial(num - 1)

n=int(input())
if n==2:
    print(1)
else:
    print(factorial(n-1)/(n*n/2))