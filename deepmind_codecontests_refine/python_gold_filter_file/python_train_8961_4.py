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

MOD = 1000000007
MAX=2147483647
MIN=-2147483648
p=input
# for _ in range(o()):
n=o()
l=op()
c=1
for i in l:
    f=[0]*(n+1)
    f[c]=1
    x=i
    while f[x]==0:
        f[x]=1
        x=l[x-1]
    print(x,end=' ')
    c+=1


