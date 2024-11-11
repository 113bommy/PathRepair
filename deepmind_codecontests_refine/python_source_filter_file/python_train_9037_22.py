N=int(input())
A=[int(input()) for i in range(N)]

if A[0]>0:
  print(-1)
  exit(0)
for i in range(1,N):
  if A[i-1]+1<A[i]:
    print(-1)
    exit(0)
    

ans=0
for i in reversed(range(1,N)):
  if A[i]<=A[i-1]+1:
    ans+=1
  else:
    ans+=A[i]
print(ans)
    