from bisect import bisect_right
N, M, V, P = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

A_m = sorted(set(A))
n = len(A_m)
ok = n-1
ng = -1
while ng+1 < ok:
    c = (ok+ng)//2
    a = A_m[c]
    idx = bisect_right(A, a)
    if idx >= N-P:
        ok = c
        continue
    if N-V < A[-P]-a:
        ng = c
        continue
    s = 0
    for aa in A[-P:idx-1:-1]:
        s += aa-a
    if s > M*(N-V):
        ng = c
    else:
        ok = c
a = A_m[ok]
print(sum(a<=aa for aa in A))
