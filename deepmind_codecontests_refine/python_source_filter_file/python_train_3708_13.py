n, p, q, r = map(int, input().split())
v = list(map(int, input().split()))
d = [0]*n
for i in range(n-1, -1, -1):
    if i == n-1:
        d[i] = r*v[i]
    elif d[i+1] > r*v[i]:
        d[i] = d[i+1]
    else:
        d[i] = r*v[i]
now, ans = -3*(10**18), 0
for i in range(n):
    if i == 0:
        now = p*v[i]
    elif now < p*v[i]:
        now = p*v[i]
    ans = max(ans, now + q*v[i] + d[i])
print(ans)
