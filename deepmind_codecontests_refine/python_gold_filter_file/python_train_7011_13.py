import math
n, m = map(int, input().split())

ans = 0

for i in range(max(n,m)+1):
    for j in range(max(n,m)+1):
        if pow(i, 2) + j == n and i + pow(j, 2) == m:
            ans += 1

print(ans)