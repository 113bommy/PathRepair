from bisect import bisect_left
N,A,B=map(int,input().split())
inf,mod=float("inf"),10**9+7
S=[int(input()) for i in range(N)]
St_A=[0]*N
St_B=[0]*N
J_A,J_B=[0],[0]
for i in range(N):
  St_A[i]=bisect_left(S,S[i]+A)-1
  St_B[i]=bisect_left(S,S[i]+B)-1
  J_A.append(J_A[-1]+int(St_A[i]!=i))
  J_B.append(J_B[-1]+int(St_B[i]!=i))
  
#print(St_A,St_B)
#print(J_A,J_B)

dp_A=[0]*N
dp_B=[0]*N
dp_A[-1],dp_B[-1]=1,1
for i in range(N-1)[::-1]:
  if St_A[i]==i:
    dp_A[i]=(dp_A[i+1]+dp_B[i+1])%mod
  else:
    if J_B[St_A[i]]-J_B[i+1]==0:
      dp_A[i]=dp_B[St_A[i]]
    else:
      dp_A[i]=0
  if St_B[i]==i:
    dp_B[i]=(dp_A[i+1]+dp_B[i+1])%mod
  else:
    if J_A[St_B[i]]-J_A[i+1]==0:
      dp_B[i]=dp_A[St_B[i]]
    else:
      dp_B[i]=0
#print(dp_A)
#print(dp_B)
print((dp_A[0]+dp_B[0])%mod)