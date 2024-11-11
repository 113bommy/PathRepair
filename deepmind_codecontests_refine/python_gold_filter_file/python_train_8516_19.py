N=int(input())
S=input()
dp_D,dp_M=[0]*(N+1),[0]*(N+1)
dp_DM=[0]*(N+1)
C=[]

for i in range(N):
  dp_D[i+1]=dp_D[i]
  dp_M[i+1]=dp_M[i]
  dp_DM[i+1]=dp_DM[i]
  if S[i]=="D":
    dp_D[i+1]+=1
  if S[i]=="M":
    dp_M[i+1]+=1
    dp_DM[i+1]+=dp_D[i]
  if S[i]=="C":
    C.append(i+1)
    
Q=int(input())
K=[int(k) for k in input().split()]
for k in K:
  ans=0
  for c in C:
    ans+=dp_DM[c-1]-dp_D[max(c-k,0)]*(dp_M[c-1]-dp_M[max(c-k,0)])-dp_DM[max(c-k,0)]
  print(ans)