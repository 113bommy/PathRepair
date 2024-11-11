n,k=map(int,input().split())
p=list(map(int,input().split()))
c=list(map(int,input().split()))
from collections import deque
toku=[0]*(n+1)
for i in range(1,n+1):
  ans=[0]
  d=deque()
  visit=[0]*(n+1)
  d.append(i)
  while d:
    now=d.pop()
    if visit[now]==0:
      visit[now]=1
      ans.append(ans[-1]+c[p[now-1]-1])
      d.append(p[now-1])
  syuki=sum(visit)
  if ans[-1]>=0:
    if k%syuki==0:
      toku[i]=max((k//syuki)*ans[-1],(k//syuki-1)*ans[-1]+max(ans))
      
    else:
      toku[i]=(k//syuki)*ans[-1]+max(ans[1:k%syuki+1])
  else:
    if k//syuki==0:
      toku[i]=max(ans[1:k%syuki+1])
    else:
      toku[i]=max(ans[1:])
print(max(toku[1:]))      
    