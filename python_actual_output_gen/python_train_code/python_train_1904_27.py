m = int(input())
dc = [list(map(int, input().split())) for _ in range(m)]

sm = 0
n = 0
for d, c in dc:
    sm += d * c
    n += c

ans = n - 1 + sm // 9
print(ans)
