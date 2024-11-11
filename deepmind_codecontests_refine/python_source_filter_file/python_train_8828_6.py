import sys
sys.setrecursionlimit(10000)
n, m = map(int, input().split())
G = [[] for _ in range(n)]
for _ in range(m):
    x, y = map(lambda x: int(x)-1, input().split())
    G[x].append(y)

# iを始点としたときの有効パスの最大長さ
dp = [-1] * n

def rec(s):
    if dp[s] != -1:
        return dp[s]
    
    ret = 0
    for ns in G[s]:
        ret = max(ret, rec(ns)+1)
    dp[s] = ret
    return ret

ml = 0    
for i in range(n):
    ml = max(ml, rec(i))

print(ml)
