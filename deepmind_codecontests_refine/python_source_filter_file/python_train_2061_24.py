order = input()
if "L" in order[1::2] or "R" in order[::2]:
  print("Yes")
else:
  print("No")