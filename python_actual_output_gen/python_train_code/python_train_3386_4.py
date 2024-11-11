import sys

n,  x = [int(x) for x in (sys.stdin.readline()).split()]

res = 0
k = 1
for i in range(n):
    l,  r = [int(x) for x in (sys.stdin.readline()).split()]
    res += r - (l - (l - k) % 3) + 1
    k = r + 1

print(res)


