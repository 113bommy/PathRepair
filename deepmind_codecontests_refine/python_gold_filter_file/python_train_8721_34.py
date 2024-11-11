N,M=map(int,input().split())
A=list(map(int,input().split()))
a=sum(A)
A.sort()
if A[N-M]<a/(4*M):
    print("No")
else:
    print("Yes")