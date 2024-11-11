from collections import *
n, p = map(int, input().split())
s = list(map(int, input()))
if p%10==0:
    r = 0
    for i in range(n):
        if s[i]%p==0:
            r += i+1
    print(r)
    exit()
c = Counter()
c[0] += 1
v = r = 0
k = 1
for i in s[::-1]:
    v += int(i)*k
    v %= p
    r += c[v]
    c[v] += 1
    k *= 10
    k %= p
print(r)
