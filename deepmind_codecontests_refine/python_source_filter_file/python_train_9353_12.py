from math import floor
n,l,t=map(int,input().split())
li=[]
zero=0
for _ in range(n):
  x,w=map(int,input().split())
  #zero passing
  if w==1:
    zero+=(x+t)//l
    x1=(x+t)%l
  else:
    zero+=(x-t)//l
    x1=(x-t)%l
  li.append(x1)

li.sort()
li=li[zero:]+li[:zero]
for _ in range(n):
  print(li[_])