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
    a,b,c,d=vary(4)
    if (a+b)%2!=0:
        third,fourth='Tidak','Tidak'
        if b>0:
            second='Ya'
            if a>0 or d>0:
                first='Ya'
            else:
                first='Tidak'
        else:
            first='Ya'
            second='Tidak'
            
    else:
        first,second='Tidak','Tidak'
        if b>0 or c>0:
            third='Ya'
            if a>0 or d>0:
                fourth='Ya'
            else:
                fourth='Tidak'
        else:
            third='Tidak'
            fourth='Ya'
    print(first,second,third,fourth)
        