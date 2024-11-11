N=int(input())
A=list(map(int, input().split()))
B=list(map(int, input().split()))
pre=sum(A)

for i in range(N):
  if B[i]<=A[i]:
    A[i]-=B[i]
  else:
    A[i+1]=max(0, A[i+1]-B[i]-A[i])
    A[i]=0
print(pre-sum(A))