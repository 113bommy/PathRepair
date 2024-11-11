l = list(map(int, input().split()))
s = input()
for c in s:
  if c == "S":
    l = [l[4], l[0], l[2], l[3], l[1], l[5]]
  elif c == "N":
    l = [l[1], l[5], l[2], l[3], l[4], l[0]]
  elif c == "E":
    l = [l[3], l[1], l[0], l[5], l[4], l[2]]
  else:
    l = [l[2], l[1], l[5], l[0], l[4], l[3]]
print(l[0])
