import random
import os
import sys

n = int(input())
a = int(input())
b = int(input())
c = int(input())

if a < b and a < c:
    print(a*(n-1))
elif b < a and b < c:
    print(b*(n-1))
elif n >= 1:
    if a < b:
        print(a+c*(n-2))
    else:
        print(b+c*(n-2))
else:
    print(0)
    
    
