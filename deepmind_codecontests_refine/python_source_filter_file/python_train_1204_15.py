from sys import stdin,stdout
from math import gcd, sqrt, ceil
ii1 = lambda: int(stdin.readline().strip())
is1 = lambda: stdin.readline().strip()
iia = lambda: list(map(int, stdin.readline().strip().split()))
isa = lambda: stdin.readline().strip().split()
mod = 1000000007

def primeFactors(n):
    d = set()
    while n % 2 == 0:
        d.add(2)
        n = n // 2
    for i in range(3, int(sqrt(n)) + 1, 2):
        while n % i == 0:
            d.add(i)
            n = n // i
    if n > 2:
        d.add(n)
    return d

n = iia()
arr = sorted(iia())
d = {}
for i in arr:
    cur = primeFactors(i)
    for i in cur:
        d.setdefault(i,[0])[0]+=1   
res = 0
for i in d:
    res = max(res, d[i][0])
print(res)
