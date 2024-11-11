n = int(input())
allElements = [int(i) for i in input().split()]
minimumCoins = 0
negativeCount = 0
positiveCount = 0
zeroCount = 0

for item in allElements:
    if item != 0:
        minimumCoins = minimumCoins + abs(item) - 1
        if item < 0:
            negativeCount = negativeCount + 1
        elif item > 0:
            positiveCount = positiveCount + 1
    elif item == 0:
        minimumCoins = minimumCoins + 1
        zeroCount = zeroCount + 1

if (negativeCount%2 != 0):
    if zeroCount > 0:
        minimumCoins = minimumCoins + 0
    elif (zeroCount == 0):
        minimumCoins = minimumCoins + 2

print (minimumCoins)