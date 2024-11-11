N=int(input())
A=[]
node=[]
for i in range(N):
  x,y=map(int,input().split())
  A.append((x,i,"left"))
  A.append((y,i,"right"))
  node.append((x,y))
  
A.sort()
Used=[[False,False] for i in range(N)]
Used_node=0
for i in range(N):
  if A[i][2]=="left":
    Used[A[i][1]][0]=True
    if not Used[A[i][1]][1]:
      Used_node+=1
  if A[i][2]=="right":
    Used[A[i][1]][1]=True
    if not Used[A[i][1]][0]:
      Used_node+=1
if Used_node!=N:
  ans=0
  for i in range(N):
    ans+=A[i][0]
  print(ans)
else:
  if A[0][0]:
    f=0
  else:
    f=1
  NO=0
  for i in range(N):
    if not Used[i][f]:
      NO=1
      break
  ans=0
  for i in range(N):
    ans+=A[i][0]
  ans2=float("inf")
  if NO==1:
    for w in range(N):
      if A[N][1]==w:
        ans2=min(ans2,ans-min(node[w])+A[N+1][0])
      else:
        ans2=min(ans2,ans-min(node[w])+A[N][0])
    print(ans2)
    exit()
  print(ans)
    