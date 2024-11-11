N, K, Q = [int(s) for s in input().split()]
A = [0] * N
for i in range(N):
    A[int(input()) - 1] += 1

for a in A:
    print('Yes' if (K - Q + a) > 0 else 'No')