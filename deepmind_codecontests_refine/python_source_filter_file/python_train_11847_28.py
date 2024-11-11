n,a,b = map(int,input().split())
if abs(a-b)%2 == 0:
  print(abs(a-b)//2)
else:
  print(min((a+b+1)//2,(n-a+n-b+1)//2)