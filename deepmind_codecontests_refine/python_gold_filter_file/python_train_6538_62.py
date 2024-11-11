from collections import deque
a,b=map(int,input().split())
List=[]
q=deque([[0,0]])
for i in range(a):
  l=list(input())
  for _ in range(b):
    if l[_]=="#":
      q.append([i,_])
      l[_]=0
  List.append(l)
q.popleft()
aaa=[[0,1],[0,-1],[1,0],[-1,0]]
ans=0
while q:
  h,w=q.popleft()
  for x,y in aaa:
    if 0<=h+x<a and 0<=w+y<b:
      if List[h+x][w+y]==".":
        List[h+x][w+y]=List[h][w]+1
        q.append([h+x,w+y])
        if List[h+x][w+y]>ans:
          ans=List[h+x][w+y]
print(ans)