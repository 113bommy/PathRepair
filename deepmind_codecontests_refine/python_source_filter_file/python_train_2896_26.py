from itertools import accumulate, combinations
N, K = map(int, input().split())
A = list(map(int, input().split()))

SA = list(accumulate(A)) + [0]
B = A[:]

for l, r in combinations(range(N), 2):
    B.append(SA[r] - SA[l-1])

ans = 0
for i in range(33, -1, -1):
    ans *= 2
    B1 = [b for b in B if 2**i & b]
    if len(B1) >= K:
        ans += 1
        B = B1[:]

print(ans)
