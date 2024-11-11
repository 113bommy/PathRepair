from bisect import bisect_left

N, M = map(int, input().split())
A = list(map(int, input().split()))

A.sort()

def isOverEq(n):
    cnt = 0
    for a in A:
        cnt += N - bisect_left(A, n - a)
    return cnt >= M

overEq = -1
less = 10**7
while less - overEq > 1:
    mid = (less + overEq) // 2
    if isOverEq(mid):
        overEq = mid
    else:
        less = mid

accA = [0] * (N + 1)
for i, a in enumerate(A, start=1):
    accA[i] = accA[i - 1] + a

ans = 0
cnt = 0
for a in A:
    i = bisect_left(A, overEq - a)
    ans += accA[N] - accA[i]
    ans += (N - i) * a
    cnt += N - i

ans -= max(0, cnt - M) * overEq
print(ans)
