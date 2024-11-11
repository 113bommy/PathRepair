n, m = map(int, input().split())
lens = list(map(int, input().split()))
if sum(lens) < n:
    print(-1)
    exit(0)
for i in range(m):
    if n - lens[i] < i:
        print(-1)
        exit(0)
p = [0] * m
fr = n
for i in range(m - 1, -1, -1):
    p[i] = max(fr - lens[i], i) + 1
    fr = p[i] - 1
print(*p)
###