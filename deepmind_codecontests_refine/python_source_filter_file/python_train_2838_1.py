ll = lambda: list(map(int, input().split()))
st= lambda: input()
v = lambda: map(int, input().split())
ii = lambda: int(input())
from collections import *
from math import *
from datetime import datetime
from sys import stdin, stdout
for _ in range(ii()):
    x,y,z=v()
    l=[x,y,z]
    m=max(x,y,z)
    if(l.count(m)<2):
        print("NO")
    else:
        print("YES")
        print(m,m,min(l))
