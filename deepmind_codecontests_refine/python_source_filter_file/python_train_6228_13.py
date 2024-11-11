n,m,X,Y=map(int,input().split())
x=max(list(map(int,input().split())))
y=min(list(map(int,input().split())))
if x<y and y>X:
  print("No War")
else:
  print("War")