N,M,X,Y=map(int, input().split())
x=list(map(int, input().split()))
y=list(map(int, input().split()))
x.append(X)
y.append(Y)
if max(x)>=min(y):
  print('War')
else:
  print('No War')