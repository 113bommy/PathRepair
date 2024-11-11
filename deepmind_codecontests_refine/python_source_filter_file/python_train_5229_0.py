def ii(): return int(input())
def si(): return input()
def mi(): return map(int,input().split())
def li(): return list(mi()) 

import math


for i in range(ii()):
    n,k=mi()
    a=n//k 
    b=n/k 
    if a!=b:
        a+=0.5 
    ans=math.floor(k*a)
    print(ans)