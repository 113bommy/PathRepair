import sys
from collections import *
from math import *
import re
def inp_arr():return list(map(int,input().split()))
def inp():return map(int,input().split())
def lcm(a,b):return (a*b)/gcd(a,b)
def even(n):return[False,True][0 if n%2 else 1]
max_int = sys.maxsize
mod = 10**9+7

n,m=inp()
a,b=inp_arr(),inp_arr()
c1=c2=0
for i in a:
    if not even(i):c1+=1
for i in b:
    if not even(i):c2+=1
print(min(c1,n-c1)+min(c2,m-c2))