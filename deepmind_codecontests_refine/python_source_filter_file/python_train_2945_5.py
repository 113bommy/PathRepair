t = int(input())

for _ in range(t):
  n = int(input())
  out = [[0 for i in range(n)] for i in range(n)]
  for i in range(n):
    out[i][i] = 1 
  for i in range(n):
    out[i][(i+1)%n] = 1
  for i in range(n):
    for j in range(n):
      print(out[i][j],end=" ")
    print("\b")

