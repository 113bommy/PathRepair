h, w = map(int, input().split())
a = []

for _ in range(h):
    a.append = list(map(int, input().split()))

ans = []

for i in range(h):
    for j in range(w - 1):
        if a[i][j] % 2 == 1:
            ans.append([i + 1, j + 1, i + 1, j + 2])
            a[i][j + 1] += 1

for i in range(h - 1):
    if a[i][w - 1] % 2 == 1:
        ans.append([i + 1, w, i + 2, w])
        a[i + 1][w - 1] += 1

print(len(ans))
for ans in ans:
    print(*ans)
