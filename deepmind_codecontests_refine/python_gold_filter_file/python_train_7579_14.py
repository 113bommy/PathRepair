n,k = map(int,input().split())
A = [int(input()) for i in range(n)]
A.sort()
print(min(A[i+k-1] - A[i] for i in range(n-k+1)))