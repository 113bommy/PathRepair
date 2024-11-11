from itertools import accumulate

N, M = map(int, input().split())
A = list(map(int, input().split()))

A.sort(reverse=True)
d = [0] * (A[0] * 2 + 1)
for i in range(N):
    d[A[i]] += 1
d = list(accumulate(d[::-1]))[::-1]
S = list(accumulate([0] + A))

left = 0
right = A[0] * 2 + 1
while right - left > 1:
    mid = (left + right) // 2
    m = 0
    for i in range(N):
        m += d[max(0, mid - A[i])]
    if m >= M:
        left = mid
    else:
        right = mid

ans = 0
m = 0
for i in range(N):
    t = min(d[max(0, left - A[i])], M - m)
    ans += S[t] + A[i] * t
    m += t
ans += left * (M - m)
print(ans)
