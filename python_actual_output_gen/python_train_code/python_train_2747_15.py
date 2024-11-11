n,m=map(int,input().split())
x=sorted([int(i) for i in input().split()])
if n>=m:
  print(0)
else:
  l=sorted([x(i+1)-x(i) for i in range(m-1)])
  print(sum(l[:m-n]))