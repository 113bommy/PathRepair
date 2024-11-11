n, m, k = map(int, input().split())
B = [int(a) for a in input().split()]
A = [B[i+1]-B[i] for i in range(n-1)]

A = sorted(A)
print(min(sum(A[:n-k])+k,n))
