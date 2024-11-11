# C
N, M = map(int, input().split())
H = list(map(int, input().split()))

A = [0] * N
for i in range(M):
    a, b = map(int, input().split())
    A[a-1] = max(A[a-1], H[b-1])
    A[b-1] = max(A[b-1], H[a-1])
    
res = sum([H[i] >= A[i] for i in range(N)])
print(res)