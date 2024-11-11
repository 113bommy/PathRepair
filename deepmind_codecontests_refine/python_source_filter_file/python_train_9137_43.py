n,p=map(int,input().split())
s=input()[::-1]
A=[0]*n
A[0]=int(s[0])
t=1
for i in range(1,n):
  A[i]=(int(s[i])*t+A[i-1])%p
  t=(t*10)%p
ans=0
import collections
D=collections.defaultdict(int)
D[0]=1
if p!=2 and p!=5:
  for i in range(n):
    ans+=D[p-A[i]]
    D[A[i]]+=1
  print(ans)
else:
  s=s[::-1]
  ans=0
  for i in range(n):
    if int(s[i])%p==0:
      ans+=i+1
  print(ans)