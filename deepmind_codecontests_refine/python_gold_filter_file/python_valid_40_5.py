"""
ID: happyn61
LANG: PYTHON3
PROB: loan
"""
from itertools import product
import itertools
import math
#from collections import defaultdict
import sys
import heapq
from collections import deque
MOD=1000000000007
#fin = open ('loan.in', 'r')
#fout = open ('loan.out', 'w')
#print(dic["4734"])
def find(parent,i):


    if parent[i] != i: 
        parent[i]=find(parent,parent[i]) 
    return parent[i] 

        # A utility function to do union of two subsets 
def union(parent,rank,xx,yy): 
    x=find(parent,xx)
    y=find(parent,yy)
    if rank[x]>rank[y]:
        parent[y]=x
    elif rank[y]>rank[x]:
        parent[x]=y
    else:
        parent[y]=x
        rank[x]+=1
ans=0
#NK=sys.stdin.readline().strip().split()
K=int(sys.stdin.readline().strip())
#N=int(NK[0])
#K=int(NK[1])
#M=int(NK[2])
#ol=list(map(int,sys.stdin.readline().strip().split()))
#d={0:0,1:0}

x=0
y=0

#d={"N":(0,1),"S":(0,-1),"W":(-1,0),"E":(1,0)}
for _ in range(K):
    #m,n=list(map(int,sys.stdin.readline().strip().split()))
    m=int(sys.stdin.readline().strip())
    mat=[]
    l=list(map(int,sys.stdin.readline().strip().split()))
    M=sum(l)
    mat.append(l)
    l=list(map(int,sys.stdin.readline().strip().split()))
    M=max(M,sum(l))
    mat.append(l)
    p1=[0]
    p2=[0]
    for i in range(m-1,-1,-1):
        p1.append(p1[-1]+mat[0][i])
    p1.reverse()
    for i in range(m):
        p2.append(p2[-1]+mat[1][i])
    ans=M
    for i in range(m):
        ans=min(ans,max(p1[i+1],p2[i]))
    print(ans)
    
