ll=lambda:map(int,input().split())
t=lambda:int(input())
ss=lambda:input()
lx=lambda x:map(int,input().split(x))
from math import log10 ,log2,ceil,factorial as f,gcd
#from itertools import combinations_with_replacement as cs 
#from functools import reduce
#from bisect import bisect_right as br,bisect_left as bl
#from collections import Counter


#for _ in range(t()):

n=t()
a=list(ll())

d={}

for i in range(n):
    fl=0
    for j in range(n):
        if a[i]+a[j] not in d:
            d[a[i]+a[j]]=[i+1,j+1]
        else:
            if i+1 not in d[a[i]+a[j]] and j+1 not in d[a[i]+a[j]]:
                print("yes")
                print(i+1,j+1,*d[a[i]+a[j]])
                fl=1
                break
    if fl:
        break
else:
    print("no")
    
            
