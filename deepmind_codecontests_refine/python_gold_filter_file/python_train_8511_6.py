import sys
readline = sys.stdin.readline

def gcd(a,b):
    while b:
        a, b = b, a%b
    return a

def egcd(a, b):
    if a == 0:
        return b, 0, 1
    else:
        g, y, x = egcd(b % a, a)
        return g, x - (b // a) * y, y

N = int(readline())
res = []
for i in range(1, N):
  if i*i > 8*N:
    break
  if (8*N)%i:
    continue
  res.append(i)
  res.append(8*N//i)


def sqrt(x):
    ok = 0
    ng = 10**18
    while (ng-ok) > 1:
        med = (ok+ng)//2
        if med*med <= x:
            ok = med
        else:
            ng = med
    return ok
    

M = 8*N

ans = 2*N-1
for r in res:
    if r == 1:
        continue
    u = M//r
    if u == 1 or u == 2:
        continue
    if gcd(r, u) > 2:
        continue
    gc, xx, yy = egcd(r, u)
    if gc == 1:
        xx *= 2
        yy *= 2
    xx *= -1
    yy *= -1
    xx %= u
    k = xx*r
    Ml = k*(k+2)
    j = (sqrt(1+Ml)-1)//2
    ans = min(ans, j)
print(ans)
