'''Rajat pal'''
from collections import defaultdict as df
from sys import stdin
from bisect import bisect_left as bl, bisect_right as br,insort
import heapq
from collections import deque
import math
####### Stay away from negative people. They have problem for every solution.#####
'''Rajat pal'''
from collections import defaultdict as df
from sys import stdin
from bisect import bisect_left as bl, bisect_right as br,insort
import heapq
from collections import deque
import math
####### Stay away from negative people. They have problem for every solution.######
n,m=list(map(int,input().split()))
a=[[0]* m for i in range(n)]
v=set()
ans=[]
for i in range(n):
    b=list(map(int,input().rstrip().split()))
    for j in range(m):
        a[i][j]=b[j]
    v=v|set(b)

xori=0
for i in range(n):
    xori=xori^a[i][0]
if xori!=0:
    print('TAK')
    for i in range(m):
        print('1',end=' ')
else:
    gg=0
    for i in range(n):
        for j in range(1,m):
            if a[i][0]!=a[i][j]:
                gg=1
                ansi=i
                index=j
                break
        if gg==1:
            break
    if gg==1:
        print('TAK')
        for i in range(n):
            if i==ansi:
                print(index+1,end=' ')
            else:
                print(1,end=' ')
    else:
        print('NIE')
                
                
        
    