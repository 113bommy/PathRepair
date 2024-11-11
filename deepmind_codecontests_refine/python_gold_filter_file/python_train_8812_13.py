n, k, M, D = map(int, input().split())
ans = 0
for i in range(1, D+1):
    l = n//(i*k)
    r = n//((i-1)*k + 1)
    if l <= M:
        ans = max(ans, min(M, r)*i)
print(ans)