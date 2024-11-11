import math

from itertools import accumulate

def cumsum(a):
    return list(accumulate(a))

n,k = map(int, input().split())
if n == 1:
    print(1)
    exit()
mod = 10 ** 9 + 7
now = n
big = []
for i in range(2,int(math.sqrt(n)+2)):
    d = n // i
    big.append(now - d)
    now = d
big.reverse()
l = [1] * d + big
l2 = [1] * d + big
for i in range(k-1):
    a = cumsum(l)
    a.reverse()
    count = 0
    for i,j in zip(a,l2):
        l[count] = (i * j) % mod
        count += 1
l = cumsum(l)
ans = l[-1] % mod
print(ans)
    