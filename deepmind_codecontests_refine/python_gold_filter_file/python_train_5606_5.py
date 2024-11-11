R,C,N=map(int,input().split())
E=[]
for i in range(N):
  x1,y1,x2,y2=map(int,input().split())
  if (0<x1<R and 0<y1<C) or (0<x2<R and 0<y2<C):
    continue
  if y1==0:
    E.append((x1,i))
  elif x1==R:
    E.append((R+y1,i))
  elif y1==C:
    E.append((2*R+C-x1,i))
  elif x1==0:
    E.append((2*R+2*C-y1,i))
  if y2==0:
    E.append((x2,i))
  elif x2==R:
    E.append((R+y2,i))
  elif y2==C:
    E.append((2*R+C-x2,i))
  elif x2==0:
    E.append((2*R+2*C-y2,i))
E.sort()
visited=[False]*N
stack=[]
for p in E:
  if not visited[p[1]]:
    stack.append(p[1])
    visited[p[1]]=True
  elif visited[p[1]]:
    if stack[-1]==p[1]:
      stack.pop()
    else:
      print("NO")
      exit()
print("YES")
  
    