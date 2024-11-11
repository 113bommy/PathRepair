#95644173
from collections import defaultdict as DD
from bisect import bisect_left as BL
from bisect import bisect_right as BR
from itertools import combinations as IC
from itertools import permutations as IP
from random import randint as RI
import sys
MOD=pow(10,9)+7

def IN(f=0):
    if f==0:
        return ( [int(i) for i in sys.stdin.readline().split()] )
    else:
        return ( int(sys.stdin.readline()) )

n=IN(1)
a=IN()

b0=[]
b1=[]
for i in range(n):
    if a[i]%2==0:
        b0.append(a[i])
    else:
        b1.append(a[i])
#print(b0,b1)
b0.sort(reverse=True)
b1.sort(reverse=True)
m0=len(b0)
m1=len(b1)
if abs(m0-m1)<2:
    print(0)
else:
    if m0>m1:
        print(sum(b0[m0-m1-1:]))
    else:
        print(sum(b1[m1-m0-1:]))
