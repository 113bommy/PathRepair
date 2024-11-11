from sys import stdin
from _collections import deque
mod = 10**9 + 7
import sys
sys.setrecursionlimit(10**5)
from queue import PriorityQueue
from bisect import bisect_right
from bisect import bisect_left
from collections import defaultdict
from math import sqrt,factorial,gcd,log2,inf,ceil
import heapq
input = lambda : sys.stdin.readline().rstrip()
from sys import stdin, stdout
from heapq import heapify,heappush,heappop

# min = 0
# n,m = map(int,input().split())
# maxi = n
# z = m
# while z>0:
#
#     yo = (1+sqrt(1+8*z))//2
#     maxi-=yo
#     print(yo)
#     z-=((yo)*(yo+1))//2
#
#
# maxi = max(int(maxi),0)
#
#
#
# if m>=n-1:
#     min = 0
# else:
#     min = (n)-2*(m)
# #
# if m == 0:
#     print(n,n)
#     exit()
# if n == 1 and m == 1:
#     min = 1
# print(min,maxi)
import sys
from collections import defaultdict
def diam(graph):
    n=len(graph)
    st,m=0,-1
    mark=[0]*n
    dist=[0]*n
    dist2=[0]*n
    ret=[0]*4
    q=[]
    for i in range(1,4):
        q.append(st)
        mark=[0]*n
        mark[st]=1
        dist[st]=0
        far=st
        #print(st,'st')
        #print(dist,'dist')
        #print(dist2,'dist2',i)
        while(q):
            #print(dist,'in while disttttttt')
            #print(dist2,'in while')
            u=q.pop()
            if i>1:
                dist2[u]+=dist[u]
            if dist[u]>dist[far]:
                far=u
            for v in graph[u]:
                if mark[v]:
                    continue
                mark[v]=1
                dist[v]=1+dist[u]
                q.append(v)
        ret[i]=far+1
        #print(dist,'final')
        #print(dist2,'finaldist2')
        ret[0]=dist[far]
        st=far
    print(ret)
    for i in range(n):
        if i+1==ret[2] or i+1==ret[3]:
            continue
        if m==-1 or dist2[i]>dist2[m]:
            m=i
    ret[1]=m+1
    ret[0]+=(dist2[m]-ret[0])//2
    return ret
graph=defaultdict(list)
n=int(sys.stdin.readline())
for i in range(n-1):
    u,v=map(int,sys.stdin.readline().split())
    u-=1
    v-=1
    graph[u].append(v)
    graph[v].append(u)
ans=diam(graph)
print(ans[0])
print(*ans[1:])

