N, x = map(int, input().split())
a = list(map(int, input().split()))
min_a = {}
for i in range(N):
    min_a[i] = a[i]
ans = 10 ** 18
for i in range(N):
    s = x * i
    for j in range(N):
        min_a[j] = min(min_a[j], a[(i + j) % N])
        s += min_a[j]
    ans = min(ans, s)
print(ans)