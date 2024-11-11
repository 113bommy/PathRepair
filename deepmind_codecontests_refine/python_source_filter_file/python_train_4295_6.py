import sys
input = sys.stdin.readline


def solve(mid):
    return (mid + 1) * h + mid * c >= t * (2 * mid + 1)

t = int(input())
for _ in range(t):
    h, c, t = map(int, input().split())
    if 2 * t <= h + c:
        print(2)
        continue
    if h <= t:
        print(1)
        continue

    ok = 0
    ng = 10 ** 20
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid

    ans = 10 ** 30
    t_ = (2 * ok + 1) * (2 * ng + 1)
    if ((ok + 1) * h + c * ok) * (2 * ng + 1) - t_ >= t_ - ((ng + 1) * h + c * ng) * (2 * ok + 1):
        print(2 * ng + 1)
    else:
        print(2 * ok + 1)