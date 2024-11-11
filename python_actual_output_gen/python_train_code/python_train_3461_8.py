n, m = map(int, input().split())
a = list(map(int, input().split()))
i, ans = 0, 0

while i < n:
    ans += 1
    cap = a[i]
    while i < n - 1 and a[i] + a[i+1] <= m:
        i += 1
        cap += a[i]
    i += 1

print(ans)