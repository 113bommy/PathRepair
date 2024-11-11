n = int(input())
C = [int(input()) for i in range(n)]
nc = 2 * 10 ** 5 + 3
mod = 10**9+7

A = [0] * n
B = [-1] * nc

A[-1] = 1
B[C[-1]] = n-1
# print(B)

for i in range(n-2, -1, -1):
    if B[C[i]] != -1 and B[C[i]] != i+1:
        A[i] = (A[i+1] + A[B[C[i]]]) % mod
    else:
        A[i] = A[i+1]
    B[C[i]] = i
    # print(A,B)

# print(A)
# print(B)
print(A[0])