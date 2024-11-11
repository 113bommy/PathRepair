N,K=map(int,input().split())
ls=list(map(int,input().split()))
for _ in range(K):
  if ls==[N]*N:
    break
  else:   
    R=[0]*(N)
    for i in range(N):
      R[max([0,i-ls[i]])]+=1
      if i+ls[i]+1<N:
        R[i+ls[i]+1]-=1  
    ls[0]=R[0]
    for i in range(N-1):
      ls[i+1]=ls[i]+R[i+1]   
for i in range(N):
  print(ls[i],end="")  