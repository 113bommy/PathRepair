#!/usr/bin/pypy3
# import sys
# sys.stdin = open("/home/vaibhav/python/input.txt", "r")
# sys.stdout = open("/home/vaibhav/python/output.txt", "w")
n, x = map(int, input().split())
lst = list(map(int, input().split()))
ans = 0
if x not in lst:
    lst.append(x)
    n += 1
    ans += 1
lst.sort()
rlst = list(reversed(lst))
t = lst[(n + 1) // 2 - 1]
if x == t:
    print(ans + 0)
else:
    if x < t:
        a = rlst.index(x)
        b = n - (a + 1)
    else:
        b = lst.index(x)
        a = n - (b + 1)
    if (b + 1) < a:
        print(ans + a - (b + 1))
    else:
        print(ans + b)
