def solve():
    s, n, k = map(int, input().split())
    if s == k:
        return 1
    if n < k:
        return 0
    return n//k*2*k + n%k >= s


import sys
input = lambda: sys.stdin.readline().rstrip()
t = int(input())
ans = ["NO", "YES"]
for i in range(t):
    print(ans[solve()])
