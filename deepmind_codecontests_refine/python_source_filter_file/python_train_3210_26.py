A, B, K = map(int, input().split())

m  = min(A+K+1, B+1)
for i in range(A, m):
    print(i)
n = max(A+K+1, B-K, B)
for j in range(n, B+1):
    print(j)