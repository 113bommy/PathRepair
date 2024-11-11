p,q=map(int,input().split())
if (p-q)%2==1:
  print("IMPOSSIBLE")
else:
  print(abs((p-q)//2))