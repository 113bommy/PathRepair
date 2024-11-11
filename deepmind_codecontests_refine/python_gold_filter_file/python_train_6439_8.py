A,B=map(int,input().split())
if A==B:
  print('Draw')
elif A < B and A!=1 or B==1:
  print('Bob')
else:
  print('Alice')