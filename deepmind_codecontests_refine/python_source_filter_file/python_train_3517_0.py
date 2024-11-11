n, m, k = map(int, input().split())
clusterN = [1] * n
clusterI = list(range(n))
out = [0] * n
def generateC(x):
  if clusterI[x] != x:
    minI = generateC(clusterI[x])
    clusterI[x] = minI
    return minI
  else:
    return x

def unite(x, y):
  CX = generateC(x)
  CY = generateC(y)
  if CX != CY:
    if CX > CY:
      CX, CY = CY, CX
      x, y = y, x
    clusterN[CX] += clusterN[CY]
    clusterI[CY] = CX
    generateC(y)
    

for _ in range(m):
  a, b = map(int, input().split())

  unite(a-1, b-1)
  out[a-1] -= 1
  out[b-1] -= 1

for _ in range(k):

  a, b = map(int, input().split())
  if generateC(a-1) == generateC(b-1):
    out[a1] -= 1
    out[b-1] -= 1
out = [out[i] + clusterN[generateC(i)] - 1 for i in range(n)]
print(*out)