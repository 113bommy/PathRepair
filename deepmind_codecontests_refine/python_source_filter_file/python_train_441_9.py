import sys
import math
import bisect
from sys import stdin,stdout
from math import gcd,floor,sqrt,log
from collections import defaultdict as dd
from bisect import bisect_left as bl,bisect_right as br

sys.setrecursionlimit(100000000)

ii     =lambda: int(input())
si     =lambda: input()
jn     =lambda x,l: x.join(map(str,l))
sl     =lambda: list(map(str,input().strip()))
mi     =lambda: map(int,input().split())
mif    =lambda: map(float,input().split())
lii    =lambda: list(map(int,input().split()))

ceil   =lambda x: int(x) if(x==int(x)) else int(x)+1
ceildiv=lambda x,d: x//d if(x%d==0) else x//d+1

flush  =lambda: stdout.flush()
stdstr =lambda: stdin.readline()
stdint =lambda: int(stdin.readline())
stdpr  =lambda x: stdout.write(str(x))

mod=1000000007


#main code
for _ in range(ii()):
    n=ii()
    a=lii()
    b=lii()
    c=lii()
    arr=[a[0]]
    for i in range(1,n):
        prev=arr[i-1]
        if i!=n-1:
            if a[i]==prev:
              arr.append(a[i])
            else:
               arr.append(b[i])
        else:
            next=arr[0]
            if (a[i]!=next and a[i]!=prev):
                arr.append(a[i])
            elif (b[i]!=next and b[i]!=prev):
               arr.append(b[i])
            else:
               arr.append(c[i])

    
    print(*arr)