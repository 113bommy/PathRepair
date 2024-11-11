from math import *
from collections import *
from itertools import *
from bisect import *
from operator import *
import sys
sys.setrecursionlimit(1000000)
def io():
    return map(int,input().split())
def op():
    return list(map(int,input().split()))
def o():
    return int(input())
def kl(con,x=0):
    if x==0:print('Yes') if con else print('No')
    elif x==1:print('yes') if con else print('no')
    elif x==2:print('YES') if con else print('NO')
# MOD =    1000000007
# MAX=float('inf')
# MIN=-float('inf')
p=input
# for _ in range(o()):
n=o()
l=op()
i,j=0,1
m=0
c=1
for i in range(1,n):
    if l[i]<=2*l[i-1]:
        c+=1
    else:
        c=1
    m=max(m,c)
print(m)