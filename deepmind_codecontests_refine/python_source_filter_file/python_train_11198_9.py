#!/usr/bin/python3.7
n, m = map(int, input().split())
minlen = 900000001
for i in range(m):
    t1, t2 = map(int, input().split())
    minlen = min(t2 - t1 + 1, minlen)

print(minlen)
print([i for i in list(range(minlen))*(n//minlen) + list(range(n % minlen))])
