N = int(input())
A = [int(x) for x in input().split()]
A.sort(reverse=True)
pre = 0
e1, e2 = 0, 0
for a in A:
  if pre == a:
    if e1 == 0:
      e1 = a
    elif e2 == 0:
      e2 == a
    pre = 0
  else:
    pre = a
print(e1 * e2)