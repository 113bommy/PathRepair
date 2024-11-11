h,w,n = map(int, input().split())
l   = [tuple(map(int, input().split())) for i in range(n)]
l.sort()
l  += [(h,w)]
N,B = (h + w + 1)<<1, 10**9+7
fac,inv = [1] * N, [1] * N
for i in range(2, N):
    fac[i] = (i * fac[i-1]) % B
    inv[i] = (-(B//i) * (inv[B%i])) % B
for i in range(2, N):
    inv[i] = (inv[i] * inv[i-1]) % B 
C   = lambda u, v: (((fac[u] * inv[v])) * inv[u - v]) % B
d   = []
for i in range(n+1):
    d += [C(l[i][0] + l[i][1] - 2, l[i][0] - 1)]
    for j in range(i):
        if l[j][1] < l[i][1]:
            d[i] = (d[i] + B - (d[j] * C(l[i][0] + l[i][1] - l[j][0] - l[j][1], l[i][0] - l[j][0]) % B)) % B
print(d[n])

    
