N = int(input())
A = list(map(int,input().split()))
A.sort()
print(sum(A[3*N-2:N-1:-2]))