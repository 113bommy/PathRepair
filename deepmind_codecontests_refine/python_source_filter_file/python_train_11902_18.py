import sys, math

tc = int(sys.stdin.readline())
for _ in range(tc):
    n, x, t = map(int, sys.stdin.readline().split())
    k = t // x + 1
    idx = n - k
    if idx < 0:
        print((k - 1) * (k - 2) // 2)
    else:
        print((idx + 1) * (k - 1) + (k - 1) * (k - 2) // 2)