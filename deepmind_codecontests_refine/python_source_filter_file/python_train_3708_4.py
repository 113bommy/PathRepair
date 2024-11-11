n, p, q, r = map(int, input().split())
a = list(map(int, input().split()))
pr = [-10**18] * n
pr[0] = p * a[0]
for i in range(1, n):
    pr[i] = max(pr[i - 1], p * a[i])
    
su = [-10**18]*n
su[-1] = r * a[-1]
for i in range(n - 2, -1, -1):
    su[i] = max(su[i + 1], r * a[i])
    
ans = -10**18
for i in range(n):
    ans = max(ans, pr[i] + q * a[i] + su[i])
    
print(ans)