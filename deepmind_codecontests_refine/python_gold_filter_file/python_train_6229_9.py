a,b=list(map(lambda x:int(x)-1,input().split()))
m=[[0]*50+[1]*50 for i in range(100)]
x,y=-2,0
for i in range(a):
  x+=2
  if x==50:
    x=0
    y+=2
  m[y][x]=1
x,y=49,0
for i in range(b):
  x+=2
  if x==101:
    x=51
    y+=2
  m[y][x]=0

print(100,100)
for i in range(100):
  for j in range(100):
    print("."*m[i][j]+"#"*(1-m[i][j]),end="")
  print()