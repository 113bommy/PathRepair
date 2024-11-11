N=int(input())
A=list(map(int, input().split()))
M=[0]*N
maxi=sum(A)

M[0]= sum(A[2::2])
for i in range(1,N):
  M[i]= 2*(A[i-1]-M[i-1]//2)
print(*M)