a,b,c=(int(i) for i in input().split())
for i in range(0,9):
  c=a*c-b
  print(c)
