n, x = map(int, input().split())
a = list(map(int, input().split()))
a += a
mah = [10000000000]*n
ans = float("inf")
for i in range(1, n+1):
    t = 0
    for j in range(n):
        if mah[j] > a[j + i]:
            mah[j] = a[j+i]
        t += mah[j]
    ans = min(ans, t+10*(i-1))
print(ans)