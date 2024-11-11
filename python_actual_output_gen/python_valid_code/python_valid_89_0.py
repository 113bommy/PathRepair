t = int(input())
for ww in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    med = n // 2
    ans = 0
    for i in range(med * k, n * k, n - med):
        ans += a[i]
    print(ans)