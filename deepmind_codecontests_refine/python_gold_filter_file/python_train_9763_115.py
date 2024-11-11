a,b,c,k=(int(i) for i in input().split())
if k<=a+b:
  print(min(a,k))
else:
  print(a-(k-a-b))