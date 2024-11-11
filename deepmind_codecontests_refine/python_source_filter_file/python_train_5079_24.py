from collections import deque
n,d,a=map(int,input().split())
xh=[list(map(int,input().split())) for _ in range(n)]
xh.sort()
d=2*d
ans=0
total=0
q=deque()
for i in range(n):
  x,h=xh[i]
  while len(q)>=1 and x>q[0][0]:
    total-=q.popleft()[1]
  h-=total
  if h>0:
    num=(h-1//a)+1
    damage=a*num
    ans+=num
    total+=damage
    q.append([x+d,damage])
print(ans)
