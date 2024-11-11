import math
import time
from collections import defaultdict,deque
from sys import stdin,stdout
from bisect import bisect_left,bisect_right
t=1
# t=int(input())
for _ in range(t):
    n,s=map(int,stdin.readline().split())
    if(n==1):
        if(s!=1):
            print("YES")
            print(s)
            print(s-1)
        else:
            print("NO")
    elif(s<=n+1 ):
        print("NO")
    else:
        print("YES")
        ans=[1]*(n-1)
        ans.append(s-n+1)
        print(*ans)
        print(2)

