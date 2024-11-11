N = int(input())
a = list(map(int, input().split()))

L = []

def ans(tf):
  if tf:
    print("Yes")
  else:
    print("No")
  exit()

for x in a:
  for i in range(len(L)):
    if L[i][0] == x:
      L[i][1] += 1
      break
  else:
    L.append([x, 1])
    if len(L) >= 3:
      ans(False)

if len(L) == 1:
  x = L[0][0]
  if x == N - 1 or x <= N // 2:
    ans(True)
  else:
    ans(False)
else:
  x, xn = L[0]
  y, yn = L[1]
  if abs(x - y) != 1:
    ans(False)
    exit()
  if x < y:
    x, y = y, x
    xn, yn = yn, xn
  if yn >= x:
    ans(False)
    exit()
  n = x - yn
  if n <= xn // 2:
    ans(True)
  else:
    ans(False)