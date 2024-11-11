import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time, functools,copy,random
from functools import reduce 
import operator
 
inf = float('inf')
mod = 10**9+7
def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def LS(): return input().split()
def endl(): return print('\n')
def lcm(a,b): return (a*b) // fractions.gcd(a,b)
def grayCode (n): return n ^ (n >> 1);
sys.setrecursionlimit(20000)    # adjust numbers
graph = collections.defaultdict(list)
grid = []
visited = set()
ways = ["D","U","R","L"]
dx =   [1,-1,0,0]
dy =   [0,0,1,-1]
 
def find(i) :
    if par[i] != i : par[i] = find(par[i]);
    return par[i]
def union(a, b) :
    a = find(a)
    b = find(b)
    if a == b : return False
    par[a] = b
    return True
#par = [i for i in range(n)]
def initGraph(m):
    for _ in range(m):
        u,v = LI()
        graph[u-1].append(v-1)
        graph[v-1].append(u-1)
    return graph
def initGraphW(m):
    for _ in range(m):
        a,b,c = LI()
        graph[a-1].append((b-1,c))
        graph[b-1].append((a-1,c))
 
def initGrid(h,w):
    for i in range(h):
        s = S()
        grid.append(list(s))
    return grid
 
def soe(limit):
    a = [True] * limit                          # Initialize the primality list
    a[0] = a[1] = False
 
    for (i, isprime) in enumerate(a):
        if isprime:
            yield i
            for n in range(i*i, limit, i):     # Mark factors non-prime
                a[n] = False
    return a

################## Main (Author - 9th) ################## 

for _ in range(I()):

    n = I()
    a = LI()
    x = 1

    start = a[0]
    for i in range(1,n):
        if start <= a[i]:
            x+=1
        start = a[i]

    if x == n:
        print(0)
        continue

    if a[-1] == max(a):
        print(1)
        continue
    cnt = 1
    temp = a[-1]
    mx = max(a)
    for i in reversed(range(n-1)):
        if a[i] == mx: break
        if a[i] > temp:
            temp = a[i]
            cnt+=1
    print(cnt)








