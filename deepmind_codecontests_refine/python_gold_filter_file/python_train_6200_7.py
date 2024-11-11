import sys, threading

sys.setrecursionlimit(10 ** 6)

scan = lambda: map(int, input().split())

n = int(input())
ans = 0
hash = {}
for i in scan():
    tmp = 1
    while tmp*2<=1e12:
        tmp *=2
        ans += hash.get(tmp-i, 0)
    if hash.get(i, 0):
        hash[i] += 1
    else:
        hash[i] = 1
print(ans)