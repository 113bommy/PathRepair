from copy import *
from math import *


# print(printDivisors(12))
t=int(input())
for i in range(t):
    n=int(input())
    # l=list(map(int,input().split()))
    if n<=4:
        print(1)
        continue
    else:
        if n%2==1:
            print((n-1)//2)
        else:
            print((n-2)//2)
