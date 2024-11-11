import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
a = na()

mx,mxc = 0,0
mn,mnc = 1000000,0
for i in a:
    if mx == i:
        mxc += 1
    if mn == i:
        mnc += 1
    if mx < i:
        mx = i
        mxc = 1
    if mn > i:
        mn = i
        mnc = 1

d = mx-mn


if d > 1:
    print('No')
elif d == 1:
    if mx > mnc and 2*(mx-mnc) <= mxc:
        print('Yes')
    else:
        print('No')
elif d == 0:
    if a[0] == n-1 or 2*a[0] <= n:
        print('Yes')
    else:
        print('No')