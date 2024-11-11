import sys

sys.setrecursionlimit(10 ** 6)
from bisect import *
from collections import *
from heapq import *

int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def SI(): return sys.stdin.readline()[:-1]
def MI(): return map(int, sys.stdin.readline().split())
def MI1(): return map(int1, sys.stdin.readline().split())
def MF(): return map(float, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LI1(): return list(map(int1, sys.stdin.readline().split()))
def LF(): return list(map(float, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
dij = [(0, 1), (1, 0), (0, -1), (-1, 0)]

def main():
    inf=10**9
    t=II()
    for _ in range(t):
        n,x=MI()
        cnt=defaultdict(int)
        s=0
        mx=-inf
        mn=inf
        for c in SI():
            cnt[s]+=1
            if c=="0":s+=1
            else:s-=1
            if s>mx:mx=s
            if s<mn:mn=s
        if s==0:
            if cnt[x]==0:print(0)
            else:print(-1)
            continue
        ans=0
        start=max(0,min((x-mx)//s,(x-mn)//s)-3)
        stop=max((x-mx)//s,(x-mn)//s)+3
        for m in range(start,stop):
            ans+=cnt[x-s*m]
        print(ans)

main()
