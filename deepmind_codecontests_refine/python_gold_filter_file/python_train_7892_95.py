A=list(map(int,input().split()))
K=int(input())
A.sort()
print(A[2]*2**K+A[1]+A[0])