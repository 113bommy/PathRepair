n = int(input())
b = input()
c = 0

if b[0] == ">" and b[n - 1] == "<":
  print(0)
else:
  right = -1
  left = -1
  for i in range(n):
    if b[i] == ">" and right == -1:
      right = i
    elif right >= 0 and b[i] == "<":
      left = i
  if right >= 0 and left >= 0:
    print(n - (left - right + 1))
  else:
    print(n)
