import operator

import math

def c(n,k):  
    return  int(math.factorial(n)/(math.factorial(k)*math.factorial(n-k)))

x=int(input())

print(c(x+5,5)+c(x+3,3))