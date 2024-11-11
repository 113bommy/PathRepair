import sys
input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))
dp = [-1] * n
dp[0] = 0
que = [0]

while que:
    k = que.pop()
    for v in [k - 1, k + 1, a[k] - 1]:
        if 0 <= v < n and dp[v] == -1:
            dp[v] = dp[k] + 1
            que.append(v)

print(*dp)