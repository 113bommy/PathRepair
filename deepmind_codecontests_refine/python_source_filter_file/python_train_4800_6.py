from collections import Counter
import string
import bisect
import random
import math
import sys
# sys.setrecursionlimit(10**6) 
from fractions import Fraction
def array_int():
    return [int(i) for i in sys.stdin.readline().split()]
def vary(arrber_of_variables):
    if arrber_of_variables==1:
        return int(sys.stdin.readline())
    if arrber_of_variables>=2:
        return map(int,sys.stdin.readline().split()) 
def makedict(var):
    return dict(Counter(var))
testcases=1
for _ in range(testcases):
    n=vary(1)
    a=input()
    b=input()
    i=0
    ans=0
    while i<n:
        if a[i]!=b[i]:
            if i+1<n:
                if a[i+1]!=b[i+1] and a[i]!=a[i+1]:
                    ans+=1
                    i+=1
                else:
                    ans+=1
                    i+=1
            else:
                ans+=1
                i+=1
        else:
            i+=1
    print(ans)

