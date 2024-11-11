a = list(map(int, input().split()))
ans = 0
for i in range(14):
    x, b, tru, dop = a[i], a[:], a[i] // 14, a[i] % 14
    b[i] = 0
    for j in range(i + 1, 14):
        b[j] += tru
        if dop > 0:
            b[j] += 1
            dop -= 1
    for j in range(0, i):
        b[j] += tru
        if dop > 0:
            b[j] += 1
            dop -= 1
    cnt = 0
    for j in range(14):
        cnt += b[j] if b[j]%2==0 else 0
    ans = max(ans, cnt)
print(ans)