lever = input().split("^")
leftWeight = 0
for d in range(len(lever[0])):
  if lever[0][d] != "=":
    leftWeight += int(lever[0][d])*(len(lever[0])-d)

rightWeight = 0
for d in range(len(lever[1])):
  if lever[1][d] != "=":
    rightWeight += int(lever[1][d])*(d+1)

if leftWeight > rightWeight:
  print("left")
if rightWeight > leftWeight:
  print("right")
if rightWeight == leftWeight:
  print("balance")