A=sorted(list(map(int,input().split())))
K=int(input())
print(A[2]*2*K+sum(A[:2]))