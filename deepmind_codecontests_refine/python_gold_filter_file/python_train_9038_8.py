import sys
sys.setrecursionlimit(10**8)
input = sys.stdin.readline

n, k = [int(item) for item in input().split()]
wd = []
for i in range(n):
    w, d = [int(item) for item in input().split()]
    wd.append((w, d))

l = -1; r = 10**20
while r - l > 1:
    mid = (l + r) // 2
    flower = 0
    for w, d in wd:
        if mid - w >= 0:
            flower += (mid - w) // d + 1
        if flower >= k:
            break
    if flower >= k:
        r = mid
    else:
        l = mid
print(r)
