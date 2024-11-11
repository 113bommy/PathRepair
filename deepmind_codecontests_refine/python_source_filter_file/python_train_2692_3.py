N,K,L = map(int, input().split())


class UFT:
    def __init__(self, N):
        self.UFdata = [-1] * (N+1)
        self.rank   = [0]  * (N+1)

    def find(self,x):
        UFdata = self.UFdata
        while UFdata[x] != -1:
            x = UFdata[x]
        return x

    def unite(self,x,y):
        UFdata = self.UFdata
        rank = self.rank 
        find = self.find

        x = find(x)
        y = find(y)
        if x != y:
            if rank[x] < rank[y]:
                x,y = y,x
            if rank[x] == rank[y]:
                rank[x] += 1
            UFdata[y] = x       
            

UF1 = UFT(N)
UF2 = UFT(N)
ans = [1] * (N+1)
MAP= [ [0] * (N+1) for _ in range(N+1)]
import sys
input = sys.stdin.readline
#PQ = [ [int(j) for j in input().split()] for _ in range(K)]
#RS = [ [int(j) for j in input().split()] for _ in range(L)]

for i in range(K):
    p,q = map(int,input().split())
    UF1.unite(p,q)
for i in range(L):
    p,q = map(int,input().split())#RS[i]
    UF2.unite(p, q)
counter=[]
from collections import defaultdict
cntdic =defaultdict(int)
for i in range(1,N+1):
  counter.append(UF1.find(i)+UF2.find(i)*10**6)
  cntdic[counter[-1]]+=1 

ans = [0]*(N+1)
for i in range(1,N+1):
    ans[i] = cntdic[counter[i-1]]

del ans[0]
# print(" ".join( map(lambda x: str(x), connected_num[1:])))
print(" ".join( map(lambda x: str(x), ans)))
