h, w = map(int, input().split())
c = [list(map(int, input().split())) for _ in range(10)]
a = [list(map(int, input().split())) for _ in range(h)]

for x in range(10):
    for y in range(10):
        for z in range(10):
            c[y][z] = min(c[y][z], c[y][x] + c[x][z])

ans = 0
for x in range(h):
    for y in range(w):
        if a[x][y] > 1:
            ans += c[a[x][y]][1]

print(ans)
