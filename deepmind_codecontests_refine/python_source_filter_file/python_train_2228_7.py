n, m = map(int, input().split())
f = list(map(int, input().split()))
f = sorted(f)
print(f)
ans = f[-1]
for i in range(m-n+1):
    diff = f[i+n-1] - f[i]
    if diff < ans:
        ans = diff
print(ans)