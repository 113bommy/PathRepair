a = input()
s = 0
t = 0
for i in a:
  if i == "C":
    s=1
  if i == "F" and s==1:
    t = 1
if t == 0:
  print("Yes")
else:print("No")
