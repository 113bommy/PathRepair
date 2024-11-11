import sys
input=lambda:sys.stdin.readline().rstrip()

h,w=map(int,input().split())
s=[list("."*(w+2))]+[list("."+input()+".") for _ in range(h)]+[list("."*(w+2))]
b=[[0]*(w+2)for _ in range(h+2)]
c=[[0]*(w+2)for _ in range(h+2)]
for i in range(1,h+2):
  for j in range(1,w+2):
    if s[i][j]=="*":
      b[i][j]=b[i-1][j]+1
      c[i][j]=c[i][j-1]+1
for i in range(h,-1,-1):
  for j in range(w,-1,-1):
    if s[i][j]=="*":
      b[i][j]=min(b[i][j],b[i+1][j]+1)
      c[i][j]=min(c[i][j],c[i][j+1]+1)
ans=[]
for i in range(1,h+1):
  for j in range(1,w+1):
    t=min(b[i][j],c[i][j])-1
    if t>0:
      ans.append((i,j,t))
b=[[0]*(w+2)for _ in range(h+2)]
c=[[0]*(w+2)for _ in range(h+2)]
for i,j,t in ans:
  b[i-t][j]+=1
  b[i+t+1][j]-=1
  c[i][j-t]+=1
  c[i][j+t+1]-=1
for i in range(h+1):
  for j in range(w+1):
    b[i+1][j]+=b[i][j]
    c[i][j+1]+=c[i][j]
    if i!=0 and j!=0:
      if (b[i][j]+c[i][j]>0)!=(s[i][j]=="."):
        print(-1)
        exit()

print(len(ans))
for i in ans:print(*i)