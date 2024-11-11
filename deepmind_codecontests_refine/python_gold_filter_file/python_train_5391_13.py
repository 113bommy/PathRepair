# coding: utf-8
import sys

sr = lambda: sys.stdin.readline().rstrip()
ir = lambda: int(sr())
lr = lambda: list(map(int, sr().split()))

# 全方位木DP、葉側と根側
N = ir()
graph = [[] for _ in range(N+1)]  # 1-indexed
for _ in range(N-1):
    a, b = lr()
    graph[a].append(b)
    graph[b].append(a)

MOD = 10 ** 9 + 7

fact = [1] * (N + 10)
for n in range(1, N + 10):
    fact[n] = n * fact[n - 1] % MOD
fact_inv = [1] * (N + 10)
fact_inv[-1] = pow(fact[-1], MOD - 2, MOD)
for n in range(N + 9, 0, -1):
    fact_inv[n - 1] = fact_inv[n] * n % MOD

root = 1
parent = [0] * (N+1)
order = []
stack = [root]
while stack:
    cur = stack.pop()
    order.append(cur)
    for next in graph[cur]:
        if next == parent[cur]:
            continue
        parent[next] = cur
        stack.append(next)

size_down = [0] * (N+1)  # 1-indexed
dp_down = [1] * (N+1)  # 葉側の組み合わせ
for v in order[::-1]:
    dp_down[v] *= fact[size_down[v]]
    dp_down[v] %= MOD
    p = parent[v]
    s = size_down[v] + 1
    size_down[p] += s
    dp_down[p] *= fact_inv[s] * dp_down[v]
    dp_down[p] %= MOD

size_up = [N-x-1 for x in size_down]  # 自分含めない
dp_up = [1] * (N+1)  # 根側の組み合わせ
for v in order[1:]:
    p = parent[v]
    x = dp_down[p]
    x *= dp_up[p]
    x *= fact_inv[size_down[p]]
    x *= fact[size_down[v] + 1]
    x *= pow(dp_down[v], MOD-2, MOD)
    x %= MOD
    x *= fact[size_up[v]-1]
    x *= fact_inv[size_up[p]]
    dp_up[v] = x % MOD

for xd, xu, sd, su in zip(dp_down[1:], dp_up[1:], size_down[1:], size_up[1:]):
    answer = xd * xu * fact[sd+su] * fact_inv[sd] * fact_inv[su] % MOD
    print(answer % MOD)
