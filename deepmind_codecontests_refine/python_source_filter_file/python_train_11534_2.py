
import sys
input = lambda : sys.stdin.readline().rstrip()

# 小さすぎても怒られるので
from collections import defaultdict
n = int(input())
sys.setrecursionlimit(max(1000, 2*n))

cs = [0] + [int(c) for c in input().split()]
ns = defaultdict(set)
for _ in range(n-1):
    a,b = [int(c) for c in input().split()]
    ns[a].add(b)
    ns[b].add(a)

ans = [0] * (n+1) # kを通らないパスの総数
minus = [0] * (n+1) # uの部分木のうち
minus0 = defaultdict(int)
st = {k: [] for k in range(1, n+1)}
nextu = {}
def dfs(u, prev, ans):
    global minus, st, minus0
    k = cs[u]
    st[k].append(u)
    ss = 1
    for v in ns[u]:
        if v==prev:
            continue
        nextu[u] = v
        s = dfs(v, u, ans)
        ss += s
        tmp = s - minus[v]
        ans[k] += (int(tmp * (tmp - 1) / 2) + tmp)
    st[k].pop()
    if st[k]:
        minus[nextu[st[k][-1]]] += ss
    else:
        minus0[k] += ss
#     print(ss)
    return ss

dfs(1, -1, ans)
for k in range(1, n+1):
    tmp = n - minus0[k]
    ans[k] += (int(tmp * (tmp - 1) / 2) + tmp)
    
total = int(n * (n+1) / 2)
for i in range(1, n+1):
    ans[i] = total - ans[i]
print(*ans, sep="\n")