li2=[1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912]
from functools import reduce 
from collections import defaultdict
from math import floor,sqrt
from bisect import bisect
n=int(input())
m=n
if n==1:
    print(1,0)
else:
    d=defaultdict(int)
    for i in range(2,floor(sqrt(n))+1):
        while n%i==0:
            d[i]+=1
            n//=i
    if n>1:
        d[n]+=1
    vl=(list(d.values()))
    v=max(vl)
    f=1
    if len(set(vl))==1 and (v in li2):
        f=0
    if v==1 :
        print(m,0)
    else:
        print(d)
        kl=list(d.keys())
        p=reduce((lambda x, y: x * y),kl) 
        i=bisect(li2,v)
        if li2[i-1]==v:
            print(p,i-1+f)
        else:
            print(p,i+f)