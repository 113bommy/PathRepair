n,a,b=map(int,input().split())
if a>b or (n==1 and a!=b):
  print(0)
  exit()
else:
  print((a-b)*max(n-2,0)+1)