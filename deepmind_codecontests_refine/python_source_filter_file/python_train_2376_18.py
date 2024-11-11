h, w = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(h)]

ans = []
for i in range(h):
    for j in range(w - 1):
        if arr[i][j] % 2 == 1:
            arr[i][j] -= 1
            arr[i][j + 1] += 1
            ans.append([i + 1, j + 1, i + 1, j + 2])

for i in range(h - 1):
    if arr[i][w - 1] % 2 == 1:
        arr[i][w - 1] -= 1
        arr[i + 1][w - 1] += 1
        ans.append([i + 1, w - 1, i + 2, w - 1])

print(len(ans))
for x in ans:
    print(*x)