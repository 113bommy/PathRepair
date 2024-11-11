def _sum(f, t):
    return t*(t+1)//2 - f*(f-1)//2

n, x = map(int, input().split())
a = list(map(int, input().split()))
a += a
l = r = n
lf = -1
total = x
curr = 0
while total:
    lf = max(a[l]-total+1, 1)
    curr += _sum(lf, a[l])
    total -= a[l]-lf+1
    if total:
        l -= 1
sol = curr
while r+1 < 2*n:
    r += 1
    curr += _sum(1, a[r])
    total -= a[r]
    while total < 0:
        if a[l]-lf+1 == -total:
            curr -= _sum(lf, a[l])
            total = 0
            lf = 1
            l += 1
        elif a[l]-lf+1 > -total:
            curr -= _sum(lf, lf-total-1)
            lf -= total
            total = 0
        else:
            curr -= _sum(lf, a[l])
            total += a[l]-lf+1
            lf = 1
            l += 1
    sol = max(sol, curr)
 
print(sol)