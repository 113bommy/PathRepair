a,b=map(int,input().split())
if (a+b)%3 or a%3 or b%3:
  print('Impossible')
else:
  print('Possible')