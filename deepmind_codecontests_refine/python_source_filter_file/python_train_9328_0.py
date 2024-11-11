import math,sys
#from itertools import permutations, combinations;import heapq,random;
from collections import defaultdict,deque
import bisect as bi
def yes():print('YES')
def no():print('NO')
#sys.stdin=open('input.txt','r');sys.stdout=open('output.txt','w');
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
class DSU:
    def __init__(self,n):
        self.parent=[i for i in range(n+1)]
        self.rank=[0 for i in range(n+1)]
    

    def find_set(self,v):
        if v==self.parent[v]:
            return v
        self.parent[v]=self.find_set(self.parent[v])
        return self.parent[v]

    def union(self,a,b):
        a=self.find_set(a)
        b=self.find_set(b)
        if a!=b:
            if self.rank[a]<self.rank[b]:
                a,b=b,a
            self.parent[b]=a
            if self.rank[a]==self.rank[b]:
                self.rank[a]+=1
def main():
    try:
        n=I()
        l=list(enumerate(list(In()),start=1))
        l.sort(key=lambda x:x[1])
        dsu=DSU(n)
        for i in range(n):
            dsu.union(i+1,l[i][0])
        d=defaultdict(list)
        for i in range(1,n+1):
            d[dsu.parent[i]].append(i)
        print(len(d))
        for x in d:
            print(len(d[x]),*d[x])
        
    except:
        pass
        
M = 998244353
P = 1000000007
 
if __name__ == '__main__':
    # for _ in range(I()):main()
    for _ in range(1):main()
#End#

#        ******************* All The Best *******************   #