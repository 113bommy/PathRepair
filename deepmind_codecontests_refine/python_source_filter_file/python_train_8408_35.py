x=int(input())
a=0
b=64

while True:
  t=a**5+b**5
  if t==x:
    break
  if t>x:
    b-=1
  else:
    a+=1
print(a,b)