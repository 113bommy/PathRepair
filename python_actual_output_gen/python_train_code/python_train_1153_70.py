A,B=map(int,input().split())
num=(A*B)%3
if num==0:
  print('Possible')
else:
  print('Impossible')