a,b,c,k=map(int,input().split())
if(k<=a+b):
  print(k)
else:
  print(a-(k-(a+b)))