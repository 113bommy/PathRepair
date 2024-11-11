from math import gcd
n = int(input())
a = list(map(int ,input().split()))
b = min(a)
c = max(a)
d = 1
ans1 = 10 ** 18
ans2 = 10 ** 18
k = 0
for i in a:
    k += c - i
k1 = 0
for i in range(n):
    k1 = gcd(c - a[i], k1)
while d * d <= (c - b):
    if k1 % d == 0:
        if k // d < ans1:
            ans1 = k // d
            ans2 = d
    if k1 % (c // d) == 0:
        if k // ((c - b) // d) < ans1:
            ans1 = k // ((c - b) // d)
            ans2 = ((c - b) // d)
    d += 1
print(ans1,end=' ')
print(ans2)