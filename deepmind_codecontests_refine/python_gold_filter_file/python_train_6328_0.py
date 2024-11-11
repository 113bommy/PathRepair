N=int(input())

M=[[0]*10 for _ in range(10)]

for i in range(1,N+1):
  S=str(i)
  M[int(S[0])][int(S[-1])]+=1
ans=0
for i in range(10):
  for j in range(10):
    ans+=M[i][j]*M[j][i]
    
print(ans)