from collections import defaultdict,deque
import sys,heapq,bisect,math,itertools,string,queue
sys.setrecursionlimit(10**8)
INF = float('inf')
mod = 10**9+7
eps = 10**-7
def inpl(): return list(map(int, input().split()))
def inpl_str(): return list(input().split())

def Find(x):    #xの根を返す
    global table

    if table[x] == x:
        return x
    else:
        table[x] = Find(table[x])    #親の更新(根を直接親にして参照距離を短く)
        size[x] = size[table[x]]
        return table[x]

def Unite(x,y):    #xとyを繋げる
    global size
    global rank
    x = Find(x)
    y = Find(y)
    sx = Size(x)
    sy = Size(y)

    if x == y:
        return

    if rank[x] > rank[y]:
        table[y] = x
        size[x] = sx + sy
    else:
        table[x] = y
        size[y] = sx + sy
        if rank[x] == rank[y]:
            rank[y] += 1

def Check(x,y):
    if Find(x) == Find(y):
        return True
    else:
        return False

def Size(x):
    return size[Find(x)]

table = [i for i in range(10**5+1)]    #木の親 table[x] == x なら根
rank  = [1 for i in range(10**5+1)]    #木の長さ
size  = [1 for i in range(10**5+1)]    #集合のサイズ


N = int(input())
xys = [inpl() for _ in range(N)]
xys.sort()
tatedict = defaultdict(list)
xx = set()
for x,y in xys:
    tatedict[x].append(y)
    xx.add(x)

for x in xx:
    s = tatedict[x][0]
    for t in tatedict[x]:
        if not Check(s,t):
            Unite(s,t)

ans = 0
for x in xx:
    s = tatedict[x][0]
    ans += Size(s) - len(tatedict[x])

print(ans)
