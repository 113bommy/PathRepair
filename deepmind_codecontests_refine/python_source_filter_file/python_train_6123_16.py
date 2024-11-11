from sys import setrecursionlimit
setrecursionlimit(10**6)

MOD = 10**9 + 7

N = int(input())
G = [[] for _ in range(N)]

for _ in range(N-1):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    G[x].append(y)
    G[y].append(x)

def dfs(pos: int, par: int):
    # posが白の時 -> 子はなんでも良い
    # posが黒の時 -> 子は全て白
    white = 1
    black = 1
    for v in G[pos]:
        if v != par:
            tmp = dfs(v, pos)
            white *= sum(tmp)
            black *= tmp[0]
            white %= MOD
            black %= MOD
    return [white, black]  # [白, 黒]

print(sum(dfs(0, 0)))