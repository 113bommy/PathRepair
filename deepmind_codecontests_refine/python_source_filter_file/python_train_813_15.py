H,W = map(int,input().split())
A = []
for i in range(H):
  A.append(list(input()))

for h in range(H):
  for w in range(W):
    if A[h][w] == "#":
      print("#",end="")
    elif A[h][w] == ".":
      c = 0 
      for i in range(-1,2):
        for j in range(-1,2):
          if 0<=h+i<=h and 0<=w+j<=w and A[h+i][w+j]=="#":
            c+=1
      print(c,end="")
  print("")