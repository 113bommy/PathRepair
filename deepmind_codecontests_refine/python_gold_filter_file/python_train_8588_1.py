def R(): return map(int, input().split())
def I(): return int(input())
def S(): return str(input())

def L(): return list(R())

from collections import Counter 

import math
import sys


from itertools import permutations

n=I()
a=[]
for _ in range(n):
    b,c=R()
    a.append([c,b])

a.sort()
c,b=a[0]
cnt=1

for i in range(1,n):
    x,y=a[i]
    if y>c:
        c,b=x,y
        cnt+=1

print(cnt)
#








