N, M = map(int, input().split())
c = [list(map(int, input().split())) for i in range(M)]
r = 0
bridge = N
for i in range(M):
  a, b = c[M-1-i]
  if(a > bridge or bridge >= b):
    r += 1
    bridge = a
print(r)