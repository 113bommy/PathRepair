a,b,c=map(int,input().split())
w=a-b
if(w>b):
  b=b+1
  print(b)
else:
  print(w)
