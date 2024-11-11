from bisect import bisect_left

N, M = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

def count(x):
    ret = 0
    for a in A:
        ret += N - bisect_left(A, x - a)
    return ret

overEq = 0
less = 10**7
while less - overEq > 1:
    mid = (less + overEq) // 2
    if count(mid) >= M:
        overEq = mid
    else:
        less = mid

ans = 0
cnt = [0] * N
for a in A:
    i = (N - bisect_left(A, overEq - a))
    ans += i * a
    if i > 0:
        cnt[-i] += 1
for i in range(1, N):
    cnt[i] += cnt[i - 1]
for a, c in zip(A, cnt):
    ans += a * c

ans -= overEq * (count(overEq) - M)

print(ans)
