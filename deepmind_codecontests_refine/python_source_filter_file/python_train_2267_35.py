x,n=map(int, input().split())
a=list(map(int, input().split()))

for y in range(x+1):
  for b in[1,-1]:
    c=x+y*b
    if a.count(c)==0:
      print(c)
      exit()