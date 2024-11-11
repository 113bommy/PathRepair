inp = input().split()
n = int(inp[0])
k = int(inp[1])
d = int(inp[2])

if (n < d):
  print(0)
else:
  D = [[0 for i in range(n + 1)], [0 for j in range(n + 1)]]
  D[0][0] = 0
  D[1][0] = 0
  for j in range(n):
    #print(j)
    if (j + 1 <= k) and (d <= j + 1):
      D[1][j + 1] = 1
    elif (j + 1 <= k) and (d > j + 1):
      D[0][j + 1] = 1
    #print(D[1][j + 1])
    #print(D[0][j + 1])
    for i in range(d - 1):
      if (j - i - 1>= 0):
        D[1][j + 1] += D[1][j - i]
        D[0][j + 1] += D[0][j - i]
        #print(D[1][j - i])
        #print(D[1][j + 1])
        #print("here")
      else:
        break
    #print()
    for i in range(k - d + 1):
      if (j + 1 - d - i>= 0):
        D[1][j + 1] += D[1][j + 1 - i - d] + D[0][j + 1 - i - d]
        #print("here2")
      else:
        break
  print(D[1][n] % 1000000007)