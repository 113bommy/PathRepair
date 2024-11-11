# Junior's Prob005 (Class #1) - Homework #1
#
# CodeForces White Sheet
#
# https://codeforces.com/problemset/problem/1216/C

import sys

# read in the rectangles, from stand input
line1Input = input()
line2Input = input()
line3Input = input()
word1Input = line1Input.split()
word2Input = line2Input.split()
word3Input = line3Input.split()

# parse the x,y coordinates of the sheets
whiteX1 = int(word1Input[0])
whiteY1 = int(word1Input[1])
whiteX2 = int(word1Input[2])
whiteY2 = int(word1Input[3])

black1X1 = int(word2Input[0])
black1Y1 = int(word2Input[1])
black1X2 = int(word2Input[2])
black1Y2 = int(word2Input[3])

black2X1 = int(word3Input[0])
black2Y1 = int(word3Input[1])
black2X2 = int(word3Input[2])
black2Y2 = int(word3Input[3])

# can white sheet be seen?
results = "UNKNOWN"

def mySwap (a, b):
    return (b,a)

# swap black sheet if needed
if (black1X1 > black2X1):
    # swap the black sheets
    black1X1,black2X1 = mySwap(black1X1,black2X1)
    black1Y1,black2Y1 = mySwap(black1Y1,black2Y1)
    black1X2,black2X2 = mySwap(black1X2,black2X2)
    black1Y2,black2Y2 = mySwap(black1Y2,black2Y2)

if ((black1X1 <= whiteX1) and (black1X2 >= whiteX2) and (black1Y1 <= whiteY1) and (black1Y2 >= whiteY2)):
    # case 1: black1 covers the whole white sheet
    results = "NO"
elif ((black2X1 <= whiteX1) and (black2X2 >= whiteX2) and (black2Y1 <= whiteY1) and (black2Y2 >= whiteY2)):
    # case 2: black2 covers the whole white sheet
     results = "NO"
elif ((black1X1 <= whiteX1) and (black1X2 >= whiteX2) and (black2X1 <= whiteX1) and (black2X2 >= whiteX2)):
    # the black sheets are at least as wide as the white sheet. Need to look at the height overlap now
    if ((black1Y1 <= whiteY1) and (black1Y2 >= black2Y1) and (black2Y2 >= whiteY2)):
        results = "NO"
    elif ((black2Y1 <= whiteY1) and (black2Y2 >= black1Y1) and (black1Y2 >= whiteY2)):
        results = "NO"
    else:
        results = "YES"
elif ((black1Y1 <= whiteY1) and (black1Y2 >= whiteY2) and (black2Y1 <= whiteY1) and (black2Y2 >= whiteY2)):
    # the black sheets are at least as tall as the white sheet. Need to look at the width overlap now
    if ((black1X1 <= whiteX1) and (black1X2 >= black2X1) and (black2X2 >= whiteX2)):
        results = "NO"
    if ((black2X1 <= whiteX1) and (black2X2 >= black1X1) and (black1X2 >= whiteX2)):
        results = "NO"
    else:
        results = "YES"
else:
    results = "YES"
    
print(results)
