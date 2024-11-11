a,b = map(int,input().split())
if abs(a-b)%2==0:
  print(abs(a-b)//2)
else:
  print('IMPOSSIBLE')