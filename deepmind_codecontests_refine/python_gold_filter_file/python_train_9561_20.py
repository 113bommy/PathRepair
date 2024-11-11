n,c=map(int,input().split())
xpos=[]
ypos=[]
pos=[]
for _ in range(n):
  x,y=map(int,input().split())
  xpos.append(x)
  ypos.append(y)
  pos.append([x,y])
xpos=sorted(xpos)
ypos=sorted(ypos)
ans=10**20
for i in range(n):
  for j in range(i+1,n):
    for k in range(n):
      for l in range(k+1,n):
        lx,rx=xpos[i],xpos[j]
        ly,ry=ypos[k],ypos[l]
        cnt=0
        for tx,ty in pos:
          if lx<=tx<=rx and ly<=ty<=ry:
            cnt+=1
        if cnt>=c:
          ans=min(ans,(rx-lx)*(ry-ly))
print(ans)
