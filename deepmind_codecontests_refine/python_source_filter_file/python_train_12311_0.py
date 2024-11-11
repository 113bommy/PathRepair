for _ in range(int(input())):
  a,b,c=map(int, input().split())
  x,y=1,b
  if a>=b: x=-1
  if b*a<=c: y=-1
  print(x,y)