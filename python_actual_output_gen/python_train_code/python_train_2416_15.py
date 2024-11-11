x,y,z=tuple(map(int,input().split()))
a=x+z
b=y+z
if a>y and x>b :
  print('+')
elif y>a and b>x:
  print('-')
elif a==b:
  print('0')
else:
  print('?')