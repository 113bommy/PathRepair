import sys
from math import log2
def read():
    return sys.stdin.readline().strip()
def write(a):
    sys.stdout.write(a)
def solve(n):
    res = n
    x = 2
    while n > x:
        res += n//x
        x *= 2
    return res
def bruh():
    t = int(read())
    ans = [0]*t
    for i in range(t):
        n = int(read())
        ans[i] = solve(n)
    write('\n'.join(map(str, ans)))
bruh()

