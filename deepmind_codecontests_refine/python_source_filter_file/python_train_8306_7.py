import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n)]
for i in range(n-1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)


def dfs(v, dist, memo):
    memo[v] = dist
    for nv in graph[v]:
        if memo[nv] >= 0:
            continue
        dfs(nv, dist+1, memo)

memo = [-1] * n
dfs(0, 0, memo)

node = 0
dist = 0
for i in range(n):
    if memo[i] > dist:
        dist = memo[i]
        node = i

memo = [-1] * n
dfs(node, 0, memo)

dist = max(memo)
count = dist + 1

dp = [0] * (count+1)
dp[0] = 0
dp[1] = 1
dp[2] = 0
dp[3] = 1
dp[4] = 1


if count >= 5:
    for i in range(5, count+1):
        if dp[i-2] == 1 and dp[i-1] == 1:
            dp[i] = 0
        else:
            dp[i] = 1

if dp[count]:
    print("First")
else:
    print("Second")

