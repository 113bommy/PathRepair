N, K = map(int,input().split())
A = list(map(int,input().split()))

for i in range(K+1, N+1):
    print('Yes') if A[i - K] < A[i] else print('No')