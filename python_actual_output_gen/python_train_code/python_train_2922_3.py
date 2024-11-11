def visit(doctors, i, ret):
  s, d = doctors[i]
  t = ret - s
  if t < 0:
    return s
  return ((t+(d-1))//d)*d+s




n = int(input())
doctors = []
for i in range(n):
  s, d = list(map(int, input().split(' ')))
  doctors.append((s,d))


ret = 0
for i in range(n):
  ret = visit(doctors, i, ret)

print(ret)