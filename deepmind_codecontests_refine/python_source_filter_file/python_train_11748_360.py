X,A,B=map(int, input().split())
if A>=B:
  print('delicious')
elif A+X>=N:
  print('safe')
else:
  print('dangerous')