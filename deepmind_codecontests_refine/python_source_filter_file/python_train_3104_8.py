N,M=map(int, input().split())
A=list(map(int, input().split()))
B=list(map(int, input().split()))
G={}
for i in range(1,N*M+1):
  G[i]=[]
for i in range(N):
  G[A[i]].append(i+1)
for i in range(M):
  G[B[i]].append(-(i+1))
A=sorted(A)
B=sorted(B)
ans=1
import bisect
mod=10**9+7
for i in range(N*M,0,-1):
  if len(G[i])>2:
    print(0)
    exit()
  elif len(G[i])==2:
    if G[i][0]*G[i][1]>0:
      print(0)
      exit()
  elif len(G[i])==1:
    if G[i][0]>0:
      d=bisect.bisect_left(B,i)
      ans*=M-d
      ans%=mod
    else:
      e=bisect.bisect_left(A,i)
      ans*=N-e
      ans%=mod
  else:
    d=bisect.bisect_left(B,i)
    e=bisect.bisect_left(A,i)
    f=N*M-i
    if f<0:
      exit()
    ans*=(N-d)*(M-e)-f
    ans%=mod
print(ans)