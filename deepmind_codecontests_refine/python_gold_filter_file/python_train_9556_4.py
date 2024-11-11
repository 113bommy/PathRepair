from fractions import gcd
import sys
n, x, d = map(int, input().split())
if d < 0:
    d = -d
    x = -x
if d == 0:
    print(n+1 if x != 0 else 1)
    sys.exit()
g = gcd(d, x)
mod = abs(d//g)
hani = [[] for _ in range(n+1)]
for k in range(n+1):
    l = x*k+k*(k-1)//2*d
    r = x*k+k*(n*2-k-1)//2*d+d
    hani[k%mod].append((l, 0))
    hani[k%mod].append((r, 1))
ans = 0
for i in range(n+1):
    if not hani[i]:
        break
    hani[i].sort()
    cnt = 0
    l = None
    for a, f in hani[i]:
        if f == 0:#l
            if cnt == 0:
                l = a
            cnt+=1
        else:
            cnt-=1
            if cnt == 0:
                ans+=(a-l)//d
print(ans)

            





        