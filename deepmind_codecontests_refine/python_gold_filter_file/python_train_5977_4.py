import math as mt
import sys,string
input=sys.stdin.readline
from collections import defaultdict
L=lambda : list(map(int,input().split()))
Ls=lambda : list(input().split())
M=lambda : map(int,input().split())
I=lambda : int(input())

n=I()
l=L()
m=0
g=l[0]
for i in l:
    g=mt.gcd(g,i)
    m=max(m,i)
ans=(m//g-n)
if(ans%2):
    print("Alice")
else:
    print("Bob")
