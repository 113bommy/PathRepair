import math
from sys import stdin,stdout
from collections import defaultdict
for _ in range(int(input())):
    l,r=map(int,input().split())
    if r//l<2:
        print(-1,-1)
    else:
        print(l,l*2)