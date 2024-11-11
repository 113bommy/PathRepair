N,X,Y=map(int,input().split())
N=[0]*(N+1)
for i in range(1,N):
  for j in range(i+1,N+1):
    m=min(j-i,abs(Y-j)+abs(X-i)+1)
    N[m]+=1
for k in range(1,N):
  print(A[k])
