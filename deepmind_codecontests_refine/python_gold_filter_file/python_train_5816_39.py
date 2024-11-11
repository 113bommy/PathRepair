import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


xs,ys,xt,yt = list(map(int, input().split()))
n = int(input())
xyr = [None]*(n+2)
for i in range(n):
    xyr[i] = tuple(map(int, input().split()))
from itertools import product
ns = [[] for _ in range(n+2)]
s = n
t = n+1
xyr[s] = (xs,ys,0)
xyr[t] = (xt,yt,0)
for i,j in product(range(n+2), range(n+2)):
    if i<j:
        d = max(0, ((xyr[i][0]-xyr[j][0])**2 + (xyr[i][1]-xyr[j][1])**2)**0.5 - (xyr[i][2]+xyr[j][2]))
        ns[i].append((d,j))
        ns[j].append((d,i))
def dijkstra(start):
    import heapq
    vals = [None] * (n+2)
    h = [(0, start)] # (距離, ノード番号)
    vals[start] = 0
    while h:
        val, u = heapq.heappop(h)
        if u==t:
            break
        if val>vals[u]:
          continue
        for d, v in ns[u]:
            if vals[v] is None or vals[v]>val+d:
                vals[v] = val+d
                heapq.heappush(h, (vals[v], v))
    return vals
vals = dijkstra(s)
ans = vals[t]
print(ans)
