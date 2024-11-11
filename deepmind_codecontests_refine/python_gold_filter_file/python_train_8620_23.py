mod = 10 ** 9 + 7

n = int(input())

A = []
for i in range(n):
    A.append(list(map(int, input().split())))


memo = [-1] * (1<<n)
memo[0] = 1


def dfs(state, c):
    if memo[state] != -1:
        return memo[state]
    r = 0
    for i in range(n):
        if state & (1<<i) and A[c][i]:
            r += dfs(state ^ (1<<i), c+1)
            r %= mod
    memo[state] = r
    return r


print(dfs((1<<n)-1, 0))