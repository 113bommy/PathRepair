h,w=map(int,input().split())
m=[[0for _ in range(w+2)]for _ in range(h+2)]
for y in range(h):
  s=input()
  for x in range(w):
    if s[x]=="#":
      for i in [0,1,2]:
        for j in [0,1,2]:
          m[y+j][x+i]+=1
      m[y+1][x+1]=9
for y in range(1,h+1):
  ans=""
  for x in range(1,w+1):
    if m[y][x]>8:
      ans+="#"
    else:
      ans+=str(m[y][x])
  print(ans)