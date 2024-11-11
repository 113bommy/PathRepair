n,a,b=map(int,input().split())

if abs(a-b)%2==0:
  print(abs(a-b)//2)
else:
  print(min(max(a,b)-1,(min(a,b)+(abs(a-b)-1)//2)))