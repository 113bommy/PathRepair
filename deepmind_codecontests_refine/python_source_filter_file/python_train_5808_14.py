N, A, B, C = list(map(int, input().split()))
s = [input() for _ in range(N)]

DP = [[0] * 3 for _ in range(N + 1)]
DP[0] = [A, B, C]

L = [""] * N
R = {}
R[0] = "A"
R[1] = "B"
R[2] = "C"
A = []
B = []
for i in range(N):
  t = s[i]
  if t == "AB":
    x = 0
    y = 1
  if t == "BC":
    x = 1
    y = 2
  if t == "AC":
    x = 0
    y = 2
  if DP[i][y] != 0:
    DP[i + 1] = DP[i]
    DP[i + 1][x] += 1
    DP[i + 1][y] -= 1
    L[i] = R[x]
    if x == 0:
      A.append([i, y])
    else:
      B.append([i, y])
  elif DP[i][x] != 0:
    DP[i + 1] = DP[i]
    DP[i + 1][x] -= 1
    DP[i + 1][y] += 1
    L[i] = R[y]
  else:
    if x == 0:
      if len(B) == 0:
        print("No")
        exit()
      z = 1
      k, n = B.pop()
    if x == 1:
      if len(A) == 0:
        print("No")
        exit()
      z = 0
      k, n = A.pop()
    DP[i + 1] = DP[i]
    DP[i + 1][z] -= 2
    DP[i + 1][n] += 2
    if n == x:
      x, y = y, x
    DP[i + 1][x] += 1
    DP[i + 1][y] -= 1
    if DP[i + 1][z] < 0:
      print("No")
      exit()
    L[i] = R[x]
    L[t] = R[y]

print("Yes")
for i in L:
  print(i)
