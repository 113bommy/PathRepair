from sys import stdin,stdout
from collections import Counter
from itertools import permutations
import bisect
import math
I=lambda: map(int,stdin.readline().split())
I1=lambda: stdin.readline()
#(a/b)%m =((a%m)*pow(b,m-2)%m)%m

def fun(l,k):
    length=len(l)
    c=1
    for i in range(1,length):
        c=max(l[min(i+k,length-1)]-l[i-1]-1,c)  
        #print(c)
    return c  

def solve():
    n,k=I()
    s=I1().strip()
    a=[-1]
    b=[-1]
    for i in range(n):
        if s[i]=='a':
            a.append(i)
        else:
            b.append(i)
    a.append(n)
    b.append(n)
    #print(a,b)
    print(max(fun(a,k),fun(b,k)))
      
solve()
