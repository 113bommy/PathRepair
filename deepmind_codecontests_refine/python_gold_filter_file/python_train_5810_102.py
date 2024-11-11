a,b=map(int,input().split())
if abs(a-b)%2:
  print('IMPOSSIBLE')
else:
  print((a+b)//2)