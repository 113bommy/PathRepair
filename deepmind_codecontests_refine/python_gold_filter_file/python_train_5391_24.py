import sys
reader = (s.rstrip() for s in sys.stdin)
input = reader.__next__

mod = 10**9+7

class PERM_COMB_MOD():
    def __init__(self, max_n=510000, mod=10**9+7):
        self.fac = [0]*max_n
        self.finv = [0]*max_n
        self.inv = [0]*max_n
        self.fac[0] = self.fac[1] = 1
        self.finv[0] = self.finv[1] = 1
        self.inv[1] = 1
        self.max = max_n
        self.mod = mod
        self._maesyori()

    def _maesyori(self):
        for i in range(2,self.max):
            self.fac[i] = self.fac[i-1] * i % self.mod
            self.inv[i] = self.mod - self.inv[self.mod % i] * (self.mod // i) % self.mod
            self.finv[i] = self.finv[i-1] * self.inv[i] % self.mod

n = int(input())
G = [[] for i in range(n)]
for i in range(n-1):
    a,b = map(int, input().split())
    a,b = a-1,b-1
    G[a].append(b)
    G[b].append(a)
PCM = PERM_COMB_MOD(2*n)
root = n//2

tmp = [[] for i in range(n)]
cost = [1]*n
size = [1]*n
def bfs1(root):
    rev = [(root, -1)]
    for i in range(n):
        cur, par = rev[i]
        for to in G[cur]:
            if to != par:
                rev.append((to, cur))
    for i in reversed(range(1,n)):
        cur, par = rev[i]
        size[par] += size[cur]
        if len(tmp[cur]) == 0:
            pass
        elif len(tmp[cur]) == 1:
            cost[cur] = tmp[cur][0]
        else:
            size_sum = 0
            inv_sum = 1
            count_sum = 1
            for to in G[cur]:
                if to != par:
                    size_sum += size[to]
                    inv_sum *= PCM.finv[size[to]]
                    inv_sum %= mod
                    count_sum *= cost[to]
                    count_sum %= mod
            cost[cur] = PCM.fac[size_sum] * inv_sum * count_sum % mod
        tmp[par].append(cost[cur])

bfs1(root)

ans = [0]*n
def bfs2(root):
    rev = [(root, -1, 1)]
    for i in range(n):
        cur, par, d_par = rev[i]
        size_par = n - size[cur]
        size_sum = 0
        inv_sum = 1
        count_sum = 1
        for to in G[cur]:
            if to != par:
                size_sum += size[to]
                inv_sum *= PCM.finv[size[to]]
                count_sum *= cost[to]
            else:
                size_sum += size_par
                inv_sum *= PCM.finv[size_par]
                count_sum *= d_par
            inv_sum %= mod
            count_sum %= mod
        ans_i = PCM.fac[size_sum]*inv_sum*count_sum % mod
        ans[cur] = ans_i
        for to in G[cur]:
            if to == par:
                continue
            b = size[to]
            bb = cost[to]
            d_nxt = ans_i * PCM.fac[b] * pow(bb, mod-2, mod) * PCM.fac[size_sum-b] * PCM.finv[size_sum] % mod
            rev.append((to, cur, d_nxt))
bfs2(root)
print(*ans, sep="\n")
