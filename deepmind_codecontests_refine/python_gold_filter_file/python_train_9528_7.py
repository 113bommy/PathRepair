import operator

import math

def c(n,k):  
    return  int(math.factorial(n)/(math.factorial(k)*math.factorial(n-k)))

x=int(input())

print(c(x+4,5)*c(x+2,3))