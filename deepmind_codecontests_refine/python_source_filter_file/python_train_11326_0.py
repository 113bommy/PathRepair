H,W,A,B = map(int,input().split())
for i in range(B):
  print("0"*A+"1"*(W-A))
for j in range(H-B):
  print("1"*A+"0"*(H-B))