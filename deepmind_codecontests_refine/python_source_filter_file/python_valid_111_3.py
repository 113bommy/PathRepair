from collections import Counter
import string
import math
import bisect
#import random
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
testcases=vary(1)
for _ in range(testcases):
    n=vary(1)
    rem=2*n-2
    j=1
    count=0
    while 1:
        print('('*(rem//2)+'()'*j+')'*(rem//2))
        rem-=2*j
        count+=1
        if count==n:
            break
        j+=1