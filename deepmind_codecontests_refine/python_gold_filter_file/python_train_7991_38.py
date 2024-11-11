N, K = map(int, input().split())
A = list(map(int, input().split()))
A.sort()

hi = 10**18
lo = 0

while hi - lo > 1:
    mid = (hi + lo) // 2
    cut = 0
    for i in range(N):
        cut += (A[i] + mid - 1) // mid - 1
    if cut <= K:
        hi = mid
    else:
        lo = mid

print(hi)