N = int(input())
mod = 10**9+7

A = [0]*2001
A[0] = 1

for i in range(3,2001):
    A[i] = A[i-1] + A[i-3]
print(A[N]%mod)
