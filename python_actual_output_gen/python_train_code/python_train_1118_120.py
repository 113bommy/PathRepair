a,b,c=map(int,input().split())
if a>=k:
  print(a-k,b)
else:
  print(0,max(a+b-k,0))