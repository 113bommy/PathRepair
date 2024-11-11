n = int(input())
p = input()
index = 0
s = []
res = []
for i in range(n):
  if s and p[i] > s[-1][0]:
    s.append((p[i], i))

  elif s and p[i] < s[-1][0]:
    res.extend([s[-1][1]+1, i+1])
    break

  else:
    if s:
      s.append((p[i], s[-1][1]))
    else:
      s.append((p[i], i))
  # print(s)
if not res:
  print('NO')
else:
  print('YES')

  print("".join(map(str, res)))




