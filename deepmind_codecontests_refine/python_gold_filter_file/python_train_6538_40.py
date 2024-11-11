import sys
input = sys.stdin.readline
h,w=map(int,input().split())
A=[[False]*(w+2) for _ in range(h+2)]
chk,chk2=[],[]
for i in range(h):
  s=input()
  for j in range(w):
    A[i+1][j+1]=(s[j]==".")
    if s[j]=="#":
      chk.append((i+1,j+1))
ans=0
d=((1,0),(0,1),(-1,0),(0,-1))
while chk:
  for cx,cy in chk:
    for dx, dy in d:
      if A[cx+dx][cy+dy]==True:
        chk2.append((cx+dx,cy+dy))
        A[cx+dx][cy+dy]=False
  if chk2:
    ans+=1
  chk=chk2
  chk2=[]
print(ans)