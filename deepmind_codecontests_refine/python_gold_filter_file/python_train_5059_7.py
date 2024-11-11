def check(s,r):
  i=(s//50)%475
  for _ in range(25):
    i=(i*96+42)%475
    if 26+i==r:return 1
  return 0
p,x,y=map(int,input().split())
a=1
for i in range(x,y-1,-50):
  if check(i,p):exit(print(0))
x+=100
while 1:
  if check(x,p) or check(x-50,p):exit(print(a))
  x+=100;a+=1