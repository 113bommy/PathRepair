import sys
sys.setrecursionlimit(10**7)
n = int(input())
graph = {i:[] for i in range(n+1)}
for j in range(n-1):
    x, y = [int(i) for i in sys.stdin.readline().split()]
    x -= 1
    y -= 1
    graph[x].append(y)
    graph[y].append(x)

memo_ls = [[None for j in range(2)] for i in range(n+1)]
# i番目の人がj色の時の通り数 0 : 白
cur = 0
def dfs(cur, col, last):
    if memo_ls[cur][col] is not None:
        return memo_ls[cur][col]
    next_col_num = 1 if col == 1 else 2
    _sum = 1
    cnt = 0
    for _next in graph[cur]:
        if _next == last:
            continue
        cnt += 1
        res = 0
        for next_col in range(next_col_num):
            res += dfs(_next, next_col, cur)
        _sum *= max(1, res)
    if cnt == 0:
        memo_ls[cur][col] = 1
        return 1
    res = _sum % (10 ** 9 + 7)
    memo_ls[cur][col] = res
    return res
res = dfs(0,0,-1) + dfs(0,1,-1)
print(res % (10**9+7))