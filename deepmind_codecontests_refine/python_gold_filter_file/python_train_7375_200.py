N=int(input())
*A,=map(int,input().split())

A.sort()
print(sum(A[N::2]))