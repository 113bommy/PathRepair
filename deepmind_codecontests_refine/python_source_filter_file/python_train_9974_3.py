from math import gcd

n = int(input())
a = list(map(int, input().split()))

l = [0]*(n+1)
r = [0]*(n+1)

for i in range(n):
    l[i+1] = gcd(l[i], a[i])
    r[n-i-1] = gcd(r[n-i], a[n-i-1])

m = [0]*n

for i in range(n):
    m[i] = gcd(l[i], r[i+1])

print(max(m))