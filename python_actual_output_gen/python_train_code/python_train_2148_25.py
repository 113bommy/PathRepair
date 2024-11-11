n,m,X,Y=map(int,input().split())
x=list(map(int,input().split()))
y=list(map(int,input().split()))
if max(x) <= min(y):
  if X < min(y) <= Y:
    print("No War")
    exit()
print("War")