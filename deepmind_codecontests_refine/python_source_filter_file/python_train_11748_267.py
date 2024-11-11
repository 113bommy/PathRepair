X,A,B=map(int,input().split())
if B<=A:
  print("delicious")
elif B<=X:
  print("safe")
else:
  print("dangerous")