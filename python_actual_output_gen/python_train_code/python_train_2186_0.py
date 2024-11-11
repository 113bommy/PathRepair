N=int(input())

M=[[0]*10 for _ in range(10)]
for i in range(1,N+1):
  S=str(N)
  f=int(S[0])
  b=int(S[-1])
  M[f][s]+=1
  
ans=0
for i in range(10):
  for j in range(10):
    ans+=M[i][j]*M[j][i]
    
print(ans)
