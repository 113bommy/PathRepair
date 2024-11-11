from itertools import product
N, K = map(int, input().split())
*A, = map(int, input().split())

ans = 10**18
for P in product(range(2), repeat=N-1):
    if sum(P) < K-1:
        continue
    res = 0
    base = A[0]
    for i in range(N-1):
        if P[i]:
            if A[i+1] < base:
                res += (base+1 - A[i+1])
                base += 1
            else:
                base = A[i+1]
        else:
            if base < A[i+1]:
                res += (A[i+1] - base)
                base = A[i+1]
    ans = min(ans, res)
print(ans)