a,b = map(int,input().split())
if (a^b)&1:
  print('IMPOSSIBLE')
else:
  print((a+b)//2)
