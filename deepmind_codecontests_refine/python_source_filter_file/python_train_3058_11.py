import math
import time
from collections import defaultdict,deque
from sys import stdin,stdout
from bisect import bisect_left,bisect_right
a,b,n=map(int,stdin.readline().split())
if(a%b==0):
    print(str(a)+("0"*n))
else:
    temp=a*10
    poss=False
    for i in range(1,10):
        if(temp+i)%b==0:
            temp=temp+i
            n-=1
            poss=True
            break
    if(poss):
        print(str(temp)+("0"*n))
    else:
        print(-1)