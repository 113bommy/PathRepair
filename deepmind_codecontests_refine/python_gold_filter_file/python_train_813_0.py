H, W = map(int, input().split())
S =[input() for i in range(H)]

L = [""]*H
for i in range(H):
  for j in range(W):
    if S[i][j] == "#":
        L[i] += "#"
    else:
      c = sum(t[max(0,j-1):min(W,j+2)].count("#") for t in S[max(0,i-1):min(H,i+2)])
      L[i] += str(c)
for i in range(H):
  print(L[i])
