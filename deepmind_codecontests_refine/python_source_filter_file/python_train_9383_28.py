n, k, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

s = sum(a)
mv = 0

for i in range(min(n, m)):
    la = m - i
    cs = s + min(la, k*(n-i))
    cv = cs / (n - i)
    if cv > mv:
        mv = cv
    s -= a[i]

print(mv)
    
