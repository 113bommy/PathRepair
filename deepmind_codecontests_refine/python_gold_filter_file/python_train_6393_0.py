#!/usr/bin/python3

def readln(): return tuple(map(int, input().split()))

n, x = readln()
a = readln()
m = max(a)
ans = sum(a) - m
cnt = {}
for v in a:
    cnt[m - v] = cnt.get(m - v, 0) + 1
while True:
    k = min(cnt.keys())
    v = cnt[k]
    c = 0
    while v % x == 0:
        c += 1
        v //= x
    #print(cnt, k, cnt[k], c, v)
    if c:
        cnt[k + c] = cnt.get(k + c, 0) + v
        cnt.pop(k)
    else:
        break
    #print(cnt)
print(pow(x, ans + min(min(cnt.keys()), m), 10**9 + 7))
