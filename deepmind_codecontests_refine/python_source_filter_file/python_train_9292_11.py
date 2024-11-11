import bisect

n, d, m = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()

f = {0:0}
for i in range(n):
    f[i+1] = f[i] + arr[i]

k = bisect.bisect_right(arr, 16)
ans = 0
for nlo in range(k+1):
    nhg = (n-nlo+d)//(d+1)
    if nhg <= n-k:
        ans = max(ans, f[n] - f[n-nhg] + f[k] - f[k-nlo])

print(ans)
