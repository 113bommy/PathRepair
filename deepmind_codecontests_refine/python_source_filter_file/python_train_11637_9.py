N=int(input())
A=list(map(int, input().split()))
B=list(map(int, input().split()))

C=[0]*(N+1)
D=[0]*(N+1)
E=[0]*(N+1)

for i in range(N):
  C[A[i]]+=1
  D[B[i]]+=1
  E[A[i]]+=1
  E[B[i]]+=1

if max(E)>N:
  print("No")
  exit()
  
for i in range(1,N+1):
  C[i]+=C[i-1]
  D[i]+=D[i-1]

ans=0
for i in range(1,N+1):
  ans=max(ans, C[i]-D[i-1])
B=[B[(i+ans)%N] for i in range(N)]
  
print("Yes")
print(' '.join(map(str, B)))