from collections import Counter
import string
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
    num=array_int()
    maxi=max(num)
    sumt=[]
    for i in num:
        if i!=maxi:
            sumt.append(maxi-i)
    gd=sumt[0]
    ans=sumt[0]
    for i in range(1,len(sumt)):
        ans+=(sumt[i])
        gd=math.gcd(num[i],gd)
    print(ans//gd,gd)
        