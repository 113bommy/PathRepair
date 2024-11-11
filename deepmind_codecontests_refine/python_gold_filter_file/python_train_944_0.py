n = int(input())
a = [input().rstrip() for _ in range(n)]
b = [input().rstrip() for _ in range(n)]
# S M L
lenga = [[0,0,0] for _ in range(4)]
lengb = [[0,0,0] for _ in range(4)]

for i in range(n):
  t = 0
  if 'M' in a[i]:
    t = 1
  elif 'L' in a[i]:
    t = 2
  lenga[len(a[i])-1][t] += 1
  s = 0
  if 'M' in b[i]:
    s = 1
  elif 'L' in b[i]:
    s = 2
  lengb[len(b[i])-1][s] += 1
count = 0
for j in range(4):
  tmp = 0
  for k in range(3):
    tmp = max(tmp,abs(lenga[j][k] - lengb[j][k]))
  count += tmp
print(count)