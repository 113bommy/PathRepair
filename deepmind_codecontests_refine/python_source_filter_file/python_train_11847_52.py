n,a,b=map(int,input().split())
if (b-a)%2==0:
  print((b-a)/2)
else:
  x=(a+b-1)//2
  l=[x,n-x]
  print(min(l))