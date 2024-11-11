INF = 10 * 18
N = int(input())
A = list(map(int, input().split()))
res = INF
t = sum(A)
s = 0
for a in A[:-1]:
    s += a
    res = min(res, abs(t - s - s))
print(res)
