n=int(input())
l=[list(map(int,input().split())) for _ in range(n)]
a=[]
for x in range(101):
  for y in range(101):
    c=[]
    for t in l:
      if t[2]:
        c.append(t[2]+abs(x-t[0])+abs(y-t[1]))
    f=0
    if len(set(c))==1:
      f=1
      h=c[0]
      for t in l:
        if l[2]==0:
          if h-abs(x-t[0])-abs(y-t[1])>0:
            f=0
    if f:
      print(x,y,h)
      exit()