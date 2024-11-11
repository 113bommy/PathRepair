import math,sys
from collections import Counter, defaultdict
from sys import stdin, stdout
input = stdin.readline
lili=lambda:list(map(int,sys.stdin.readlines()))
li = lambda:list(map(int,input().split()))


n,k=li()
a=li()
c=[]
s=a[n-1]-a[0]
for i in range(1,n):
    c.append(a[i-1]-a[i])
c.sort()
print(c)
print(s+sum(c[:k-1]))
