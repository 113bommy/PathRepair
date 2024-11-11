import math
from collections import defaultdict
n = int(input())
p = defaultdict(int)
mod = 10 ** 9 + 7
ori = 0
for _ in range(n):
    a,b = map(int,input().split())
    if a == b == 0:
        ori += 1
        continue
    elif b < 0:
        a *= -1
        b *= -1
    elif b == 0 and a < 0:
        a *= -1
    if a == 0:
        p[(0,1)] += 1
    elif b == 0:
        p[(1,0)] += 1
    else:
        g = math.gcd(a,b)
        p[(a//g, b//g)] += 1

k = n - ori
ans = ori-1
tmp = 1
l = k
for q,num in sorted(p.items(), reverse=True):
    x,y = q
    if x <= 0:
        break
    if p[(-y, x)] >= 1:
        a,b = p[(x,y)], p[(-y, x)]
        tmp *= pow(2,a,mod) + pow(2,b,mod) - 1
        l -= a+b
tmp *= pow(2,l,mod)
print(ans+tmp)