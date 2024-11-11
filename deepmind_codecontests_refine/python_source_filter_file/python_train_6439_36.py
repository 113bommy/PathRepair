#ABC055
a,b = map(lambda x:(int(x)-2)%13,input().split())
if a > b:
  print('Alice')
elif a == b:
  print('Bob')
else:
  print('Draw')