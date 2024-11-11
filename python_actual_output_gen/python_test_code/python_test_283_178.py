x,a,b=map(int,input().split())
if a >= b:
  print('delicious')
elif x <= a-b:
  print('dangerous')
else:
  print('safe')