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
    a.append([b,c])

a.sort()
b,c=a[0]
cnt=1

for i in range(1,n):
    x,y=a[i]
    if x>c:
        b,c=x,y
        cnt+=1

print(cnt)









