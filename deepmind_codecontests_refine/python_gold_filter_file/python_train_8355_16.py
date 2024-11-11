testCases = int(input(""))

for i in range(0, testCases):
  user = input("")
  data = user.split(" ")
  finalValues = []
  jumpList = []

  n = int(data[0])
  x = int(data[1])
  y = int(data[2])

  if x < y:
    smallerNum = x
    largerNum = y
  else:
    smallerNum = y
    largerNum = x
  diff = largerNum - smallerNum
  for i in range(1, n):
    for j in range(i + 1, n + 1):
      jumps = j - i
      if diff % jumps == 0:
        jumpDiff = diff / jumps
        if smallerNum - jumpDiff * (i - 1) >= 1:
          finalValue = smallerNum + (n - i) * jumpDiff
          finalValues.append(int(finalValue))
          jumpList.append(int(jumpDiff))
      elif jumps > diff:
        break
  least = 0
  for i in range(1, len(finalValues)):
    if finalValues[i] < finalValues[least]:
      least = i
  startingNum = finalValues[least] - ((n - 1) * jumpList[least])
  allValues = []
  for i in range(1, n + 1):
    allValues.append(startingNum + jumpList[least] * (i - 1))
  print(*allValues, sep = " ")




  