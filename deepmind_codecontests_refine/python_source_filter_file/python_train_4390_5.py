ll=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
lx=lambda x:map(int,input().split(x))
#from math import log10 ,log2,ceil,factorial as fac,gcd
#from itertools import combinations_with_replacement as cs 
#from functools import reduce
#from bisect import bisect_right as br,bisect_left as bl
#from collections import Counter
 
 
 
for _ in range(t()):
    n=t()
    a=list(ll())
    a.sort()

    x=a[0]*a[-1]
    l=set()

    i=2
    while i*i<=x:
        if x%i==0:
            l.add(x//i)
            l.add(i)
        i+=1
    if a==list(l):
        print(x)
    else:
        print(-1)
        


