import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
from collections import deque

MOD = 10**9 + 7
N = int(input())
tree = dict(zip(range(N), [[] for i in range(N)]))
edge_id = {}
c = 0
for i in range(N-1):
  a, b = map(int, input().split())
  a, b = a-1, b-1
  tree[a].append(b)
  tree[b].append(a)
  edge_id[(a, b)] = c
  edge_id[(b, a)] = c + 1
  c += 2

# 部分木のサイズ
# 頂点v1 -> v2の向きを考えたときに、頂点v2を根とする部分木のサイズを計算する
size = [0] * 2*(N-1)
def calc_size(v1, v2):
  global size
  idx = edge_id[(v1, v2)]
  if size[idx]:
    return size[idx]
  children = tree[v2]
  s = 1
  for child in children:
    if child == v1:
      continue
    s += calc_size(v2, child)
  size[idx] = s
  idx_inv = edge_id[(v2, v1)]
  size[idx_inv] = N - s
  return s

# 階乗、組合せの計算
g1 = [1, 1]
g2 = [1, 1]
inverse = [0, 1]
MOD = 10**9+7
for i in range(2, 2*10**5+1):
    g1.append((g1[-1] * i) % MOD)
    inverse.append((-inverse[MOD % i] * (MOD // i)) % MOD)
    g2.append((g2[-1] * inverse[-1]) % MOD)

def comb(n, r, mod=MOD):
    if r < 0 or r > n:
        return 0
    r = min(r, n - r)
    return g1[n] * g2[r] * g2[n-r] % mod

# 頂点iに1を書くときの場合の数
ans = [0] * N
dp = [0] * 2*(N-1)
def calc_dp(v1, v2):
  global dp
  idx = edge_id[(v1, v2)]
  if dp[idx]:
    return dp[idx]
  children = tree[v2]
  s = calc_size(v1, v2)
  res = g1[s-1]
  for child in children:
    if child == v1:
      continue
    res *= calc_dp(v2, child)
    res %= MOD
    _s = calc_size(v2, child)
    res *= g2[_s]
    res %= MOD
  dp[idx] = res
  return res

def calc_ans(i):
  global ans
  global dp
  if ans[i]:
    return ans[i]
  children = tree[i]
  res = g1[N-1]
  for child in children:
    res *= calc_dp(i, child)
    res %= MOD
    _s = calc_size(i, child)
    res *= g2[_s]
    res %= MOD
  ans[i] = res
  return res

calc_ans(0)
d = deque([[0, -1]])
c = 0
while d:
  node, par = d.popleft()
  c += 1
  children = tree[node]
  for child in children:
    if child == par:
      continue
    s = calc_size(node, child)
    r = s * pow(N-s, MOD-2, MOD) % MOD
    ans[child] = ans[node] * r % MOD
    d.append([child, node])

print(*ans, sep='\n')