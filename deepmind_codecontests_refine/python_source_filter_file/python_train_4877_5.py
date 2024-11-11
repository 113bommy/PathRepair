ma = lambda :map(int,input().split())
lma = lambda :list(map(int,input().split()))
ni = lambda:int(input())
yn = lambda fl:print("Yes") if fl else print("No")
import collections
import math
import itertools
import heapq as hq
n = ni()
A = lma()
l = max(A)
cnts = [0 for i in range(l+2)]
for a in A:
    cnts[a]+=1
    cnts[a-1] +=1
    cnts[a+1] +=1
print(max(cnts))
