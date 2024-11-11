from collections import defaultdict

n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]

cnt = defaultdict(int)
for xi, yi in xy:
    for xj, yj in xy:
        cnt[(xi - xj, yi - yj)] += 1
cnt[(0, 0)] = 0
ans = n - max(cnt.values())
print(ans)
