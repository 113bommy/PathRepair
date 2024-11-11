import math,sys
#from itertools import permutations, combinations;import heapq,random;
from collections import defaultdict,deque
from heapq import heapify,heappop,heappush
import bisect as bi
def yes():print('YES')
def no():print('NO')
def I():return (int(sys.stdin.readline()))
def In():return(map(int,sys.stdin.readline().split()))
def Sn():return sys.stdin.readline().strip()
#sys.setrecursionlimit(1500)
def dict(a):
    d={} 
    for x in a:
        if d.get(x,-1)!=-1:
            d[x]+=1
        else:
            d[x]=1
    return d
def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bi.bisect_left(a, x)
    if i != len(a):
        return i
    else:            
        return -1
        
def main():
    try:
        d=defaultdict(list)
        n,m=In()
        parent=[i for i in range(n+1)]
        dist=[P]*(n+1)
        for i in range(m):
            a,b,c=In()
            d[a].append((b,c))
            d[b].append((a,c))
        pq=[]
        dist[1]=0
        heappush(pq,(0,1))
        while pq:
            node=heappop(pq)
            for x in d[node[1]]:
                v,wieght=x[0],x[1]
                if dist[v]>dist[node[1]]+wieght:
                    dist[v]=dist[node[1]]+wieght
                    parent[v]=node[1]
                    heappush(pq,(dist[v],v))
        ans=[]
        node=n
        if dist[node]==P:
            print(-1)
            return
        while parent[node]!=node:
            ans.append(node)
            node=parent[node]
        ans.append(node)
        print(*ans[::-1])


    except:
        pass
        
M = 998244353
P = 1000000000000007
 
if __name__ == '__main__':
    # for _ in range(I()):main()
    for _ in range(1):main()
#        *******************    All The Best    *******************   #