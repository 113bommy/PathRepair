N, P = map(int, input().split())
if N == 1:
  print(P)
  exit()
if N > 40:
  print(1)
  exit()
res = []
for i in range(1,P):
  x = i**N
  if i**N > P:
    break
  if P%x == 0:
    res.append(i)
print(max(res))