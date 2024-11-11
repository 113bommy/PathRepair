from heapq import *
import sys

sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

def main():
    def cost(i,j):
        x1,y1,r1=xyr[i]
        x2, y2, r2 = xyr[j]
        res=((x1-x2)**2+(y1-y2)**2)**0.5-r1-r2
        return max(res,0)

    sx,sy,gx,gy=MI()
    n=II()
    xyr=LLI(n)
    xyr=[[sx,sy,0]]+xyr+[[gx,gy,0]]
    n+=2
    to=[[] for _ in range(n)]
    for i in range(n):
        x1,y1,r1=xyr[i]
        for j in range(i):
            x2, y2, r2 = xyr[j]
            c=cost(i,j)
            to[i].append((j,c))
            to[j].append((i,c))
    hp=[]
    fin=[False]*n
    heappush(hp,(0,0))
    while hp:
        d,u=heappop(hp)
        if fin[u]:continue
        fin[u]=True
        if u==n-1:
            print(d)
            exit()
        for v,c in to[u]:
            if fin[v]:continue
            heappush(hp,(d+c,v))

main()