N,M,X,Y=sorted(map(int, input().split()))
Zx=max(map(int, input().split()))
Zy=min(map(int, input().split()))
if X < Zy and Zy <= Y and Zx < Zy:
  print('No War')
else:
  print('War')
