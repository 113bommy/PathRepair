n, d = map(int, input().split())
a = list(map(int, input().split()))
l = 0
ans = 0

for i in range(n):
    if l >= a[i]:
        t, s = divmod((l-a[i]+1), d)
        if s:
            t += 1
        if not(t):
            t += 1
        a[i] += d*t
        ans += t
    l = a[i]

print(ans)
        
