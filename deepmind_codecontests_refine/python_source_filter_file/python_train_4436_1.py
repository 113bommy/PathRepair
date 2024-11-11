r, c = map(int, input().split(' '))
arr = []
ops = []
num_ops = 0
for i in range(r):
  arr.append(list(map(int, input().split(' '))))

s1, s2 = "row", "col"
if r > c:
  arr1 = []
  for i in range(c):
    arr1.append([0]*r)
  for i in range(r):
    for j in range(c):
      arr1[j][i] = arr[i][j]
  r, c = c, r
  s1, s2 = s2, s1
  arr = arr1

for i in range(r):
  m = min(arr[i])
  if m > 0:
    arr[i] = [x -m for x in arr[i]]
    ops.append((0, i, m))
    num_ops += m

possible = True
for i in range(c):
  a = arr[0][i]
  for j in range(1, r):
    if arr[j][i] != a:
      possible = False
      break

  if possible == False:
    break

  if a > 0:
    ops.append((1, i, a))
    num_ops += a


if possible:
  print(num_ops)
  for i in ops:
    if i[0] == 0:
      for k in range(i[2]):
        print(s1 + str(i[1]+1))
    else:
      for k in range(i[2]):
        print(s2 + str(i[1]+1))
else:
  print(-1)
