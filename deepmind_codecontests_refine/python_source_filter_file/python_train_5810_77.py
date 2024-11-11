a,b=map(int,input().split())
if (a-b)%2==1:
  print('IMPOSSIBLE')
else:
  print(abs(a-b)//2)