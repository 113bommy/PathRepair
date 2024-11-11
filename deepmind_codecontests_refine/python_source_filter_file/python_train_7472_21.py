n = int(input())
lst_left = []
lst_right = []
total = 0
for i in range(n):
  s = input()
  h = 0
  b = 0
  for e in s:
    if e == "(":
      h += 1
    else:
      h -= 1
      b = min(b, h)
  if h>=0:
    lst_left.append((b, h))
  else:
    lst_right.append((b-h, -h))
  total += h
#lst_left = sorted(lst_left, key=lambda x:x[1], reverse=True)
lst_left = sorted(lst_left, key=lambda x:x[0], reverse=True)
#lst_right = sorted(lst_right, key=lambda x:x[1], reverse=True)
lst_right = sorted(lst_right, key=lambda x:x[0], reverse=True)

if total != 0:
  print("No")
h = 0
for i in range(len(lst_left)):
  if h + lst_left[i][0] < 0:
    print("No")
    exit()
  else:
    h += lst_left[i][1]
h = 0
for i in range(len(lst_right)):
  if h + lst_right[i][0] < 0:
    print("No")
    exit()
  else:
    h += lst_right[i][1]
print("Yes")
  
