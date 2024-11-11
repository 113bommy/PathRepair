from math import *
from collections import *
from operator import itemgetter
import bisect
ii = lambda: int(input())
iia = lambda: list(map(int,input().split()))
isa = lambda: list(input().split())
I = lambda:list(map(int,input().split()))
chrIdx = lambda x: ord(x)-96
idxChr = lambda x: chr(96+x)

t = ii()

for i in range(t):
    m,n = iia()
    ans = []
    if(m==1):
        ans.append('B'+'W'+'B'*(n-2))
    elif(n==1):
        ans.append('B')
        ans.append('W')
        for j in range(m-2):
            ans.append('B')
    else:
        ans.append('W'+'B'*(n-1))
        for j in range(m-1):
            ans.append('B'*(n))
    for j in range(m):
        print(ans[j]) 
