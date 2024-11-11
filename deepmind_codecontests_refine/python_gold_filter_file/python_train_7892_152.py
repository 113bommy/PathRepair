A=list(map(int,input().split()))
K=int(input())
A.sort()
print(A[0]+A[1]+A[2]*2**K)
