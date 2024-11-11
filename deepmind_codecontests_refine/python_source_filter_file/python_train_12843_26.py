from math import *
#from math import comb as nCr
import sys
from sys import *
def gI(): return map(int, sys.stdin.readline().strip().split())
def gL(): return list(map(int, sys.stdin.readline().strip().split()))
def SL(): return list(map(str, sys.stdin.readline().strip().split()))
t=stdin.readline
p=stdout.write
'''
for _ in range(int(t())):
    n=int(t())
    a,b=gI()
    a=gL()
'''
n,k=gI()
a=SL()
print(sum(sum('47' in c for c in x)<=k for x in a))
