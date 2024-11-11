import heapq
import sys
input = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 9)
INF = 1001001001
MAX_V = 50
MAX_S = MAX_V*50+5

n, m, s = map(int, input().split())
g = [[] for _ in range(n)]
for i in range(m):
    u,v,a,b = map(int, input().split())
    g[u-1].append((v-1,a,b))
    g[v-1].append((u-1,a,b))
cd = [list(map(int, input().split())) for _ in range(n)]

# print(g)
# print(cd)
dp = [[INF]*(MAX_S+5) for _ in range(MAX_V)]   # 頂点vに銀貨xを持っている時の時間
s = min(s, MAX_S)
q = []

def push(v,s,x):
    if s<0: return
    if dp[v][s]<=x: return
    dp[v][s] = x
    heapq.heappush(q, (x,s,v))

push(0, s, 0)
while q:
    x,s,v = heapq.heappop(q)
    if dp[v][s] != x: continue
    ns = min(s+cd[v][0], MAX_S)
    push(v, ns, x+cd[v][1])
    for to, a, b in g[v]:
        push(to, s-a, x+b)

# print(dp)
for i in range(1,n):
    print(min(dp[i][:MAX_S+5]))
    # print(dp[i][:50])
