n,a,b=map(int,input().split())
if (b-a)%2==0:
  print(int((b-a)/2))
else:
  print(int((b-a-1)/2+1+min(n-b,a-1))