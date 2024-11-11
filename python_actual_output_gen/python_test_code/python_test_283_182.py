x,a,b=map(int,input().split())
if a>b:
  print('delicious')
elif a+x<b:
  print('dangerous')
else:
  print('safe')