N,M,X,Y=map(int,input().split())
x=sorted([X]+list(map(int,input().split())))
y=sorted([Y]+list(map(int,input().split())))
if x[-1]<y[0]:
  print('No War')
else:
  print('War')