n, k = map(int, input().split())
a = list(map(int, input().split()))

cum = []
abscum = []

cu = 0
acu = 0
for i in range(n):
    cu += a[i]
    acu += max(0, a[i])
    cum.append(cu)
    abscum.append(acu)

ans = 0
for i in range(n-k+1):
    if i == 0:
        ans = max(ans, abscum[n-1] - abscum[i+k-1] + max(0, cum[i+k-1]))
    else:
        ans = max(ans, abscum[n - 1] - (abscum[i + k - 1] - abscum[i-1]) + max(0, cum[i + k - 1] - cum[i-1]))

print(ans)