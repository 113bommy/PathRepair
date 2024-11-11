n = int(input())
A = list(map(int,input().split()))
A.sort()

print(sum(A[n:2*n]))