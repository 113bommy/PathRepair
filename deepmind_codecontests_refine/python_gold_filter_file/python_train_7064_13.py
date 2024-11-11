c  = 0
s = input()
for i,si in enumerate(s):
  if si == "C":
    c = 1
  elif si == "F" and c:
    print("Yes")
    exit()
print("No")