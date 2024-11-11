def R(): return map(int, input().split())
def I(): return int(input())
def S(): return str(input())

def L(): return list(R())

from collections import Counter 

import math
import sys

n,m=R()

a=L()
a.sort()
d={}
for i in range(m):
    s=S()

    d[s]=1 if not s in d else d[s]+1

v=list(d.values())

v.sort()
min_sum=0
max_sum=0

for i in range(len(d)):
    min_sum+=v[-i]*a[i]
    max_sum+=v[i]*a[i-len(v)+len(a)]

print(min_sum,max_sum)

      
      
    
