N=int(input())
A=list(map(int,input().split()))
t=sum(a)
for i in range(N):
  A[i]=abs(A[i]*N-t)
dif = min(A)
for i in range(N):
  if dif==A[i]:
    print(i)
    break