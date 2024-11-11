from collections import deque

N, D, A=map(int, input().split())
XH=[list(map(int, input().split())) for _ in range(N)]
XH.sort(key=lambda x:x[0])
total=0
q=deque()
ans=0

for i in range(N):
  X, H=XH[i]
  while len(q) and q[0][0]<X:
    total-=q.pop()[1]
  H-=total
  if H>0:
    attack_cnt=(H-1)//A+1
    ans+=attack_cnt
    damage=attack_cnt*A
    total+=damage
    q.append([X+2*D, damage])
print(ans)