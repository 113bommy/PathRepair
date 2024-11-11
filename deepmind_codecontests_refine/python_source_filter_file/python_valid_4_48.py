"""
x + a*c1 = x + b*c2

if there is a number such that a*b < x and (a+1)b, a(b+1) > x



"""
from math import sqrt, floor
for _ in range(int(input())):
    P = int(input())
    s = floor(sqrt(P))
    if P>3:  
        print(s,s**2)
    else:
        print("-1")
    
