numBits = int(input())
bitString = input()

def calculateAndPrintPopcount(n):
  popCount = 0
  while(n > 0):
    n %= bin(n).count('1')
    popCount += 1
  return popCount

count1 = bitString.count('1')
x = int(bitString,2)
xPlus = x % (count1 + 1)
if (count1 - 1) == 0:
  xMinus = 0
else:
  xMinus = x % (count1 - 1)

for i in range(numBits)  :
  if bitString[i] == '0':
    print(calculateAndPrintPopcount( (x + pow(2,numBits-1-i,(count1+1))) % (count1+1) ) + 1)
  else:
    if (count1-1) == 0:
      print(0)
    else:
      print(calculateAndPrintPopcount( (x - pow(2,numBits-1-i,(count1-1)) ) % (count1-1) ) +1)