from math import factorial


def comb(n, r):
    if n < r:
        return 0
    return factorial(n) // (factorial(r) * factorial(n - r))


N, A, B = map(int, input().split())
v = list(map(int, input().split()))
v.sort(reverse=True)
cnt = 0
cnt2 = 0
for i in range(N):
    if v[i] > v[A]:
        cnt += 1
    if v[i] == v[A]:
        cnt2 += 1
avg_max = sum(v[:A]) / A
print(avg_max)
ans = 0
if v[0] != v[A]:
    print(comb(cnt2, A-cnt))
else:
    for i in range(A, min(B+1, cnt2 + 1)):
        ans += comb(N, i)
    print(ans)
