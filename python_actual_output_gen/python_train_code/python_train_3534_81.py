k=int(input())
a,b=map(int, input().split())
t=b-a
if k<=t:
  print('OK')
else:
  print('NG')