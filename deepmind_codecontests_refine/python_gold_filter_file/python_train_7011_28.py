def R(): return map(int, input().split())
def I(): return int(input())
def S(): return str(input())

def L(): return list(R())

from collections import Counter 

import math
import sys

from itertools import permutations

n,m=R()
cnt=0

for a in range(40,-1,-1):
    for b in range(40,-1,-1):
        if a*a+b==n and b*b+a==m:
            cnt+=1

print(cnt)