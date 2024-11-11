n = int(input())
i, j = -1000000000, 1000000000
for _ in range(n):
  s, v, a = input().split()
  v = int(v)
  if s == '>':
    if a == "Y":
      i = max(i, v + 1)
    else:
      j = min(j, v)
  elif s == "<":
    if a == "Y":
      j = min(j, v - 1)
    else:
      i = max(i, v)
  elif s == '<=':
    if a == "Y":
      j = min(j, v)
    else:
      i = max(i, v + 1)
  elif s == ">=":
    if a == "Y":
      i = max(i, v)
    else:
      j = min(j, v - 1)
print("Impossible" if i > j else i)