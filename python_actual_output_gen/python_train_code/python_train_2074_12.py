N, M, V, P = map(int, input().split())
A = list(map(int, input().split()))
A = list(reversed(sorted(A)))

def ok(x):
    if x + M < A[P]:
        return False
    sc = M * V
    for a in A[:P-1]:
        sc = sc - M
    for a in A[P-1:]:
        sc = sc - min(M, x + M - a)
    return sc <= 0

l, r = -1, N
while r - l > 1:
    m = l + (r - l) // 2
    if not ok(A[m]):
        r = m
    else:
        l = m
print(r)