def fac(n):
    ret = 1
    for i in range(2, n+1):
        ret *= i
    return ret
def upay(n, r):
    return fac(n)//(fac(r)*(fac(n-r)))
n, m, t = map(int, input().split())
ans = 0
for i in range(4, n+1):
    b = i
    g = t-b
    if g > 0 or g <= m:
        ans += upay(n, b) * upay(m, g)
print(ans)