"""
Almost every text editor has a built-in function of center text alignment. The developers of the popular in Berland text editor «Textpad» decided to introduce this functionality into the fourth release of the product.

You are to implement the alignment in the shortest possible time. Good luck!

Input
The input file consists of one or more lines, each of the lines contains Latin letters, digits and/or spaces. The lines cannot start or end with a space. It is guaranteed that at least one of the lines has positive length. The length of each line and the total amount of the lines do not exceed 1000.

Output
Format the given text, aligning it center. Frame the whole text with characters «*» of the minimum size. If a line cannot be aligned perfectly (for example, the line has even length, while the width of the block is uneven), you should place such lines rounding down the distance to the left or to the right edge and bringing them closer left or right alternatively (you should start with bringing left). Study the sample tests carefully to understand the output format better.
"""

import math
import sys

inputList = [k.strip() for k in sys.stdin]
maxLength = max(len(a) for a in inputList)

print((maxLength + 2) * '*')

leftSided  = False
firstSpace = 0
secondSpace = 0

for x in inputList:
    space = maxLength - len(x)
    if (space % 2): # space is odd
        firstSpace = math.ceil(space / 2) if leftSided else math.floor(space / 2)
        leftSided = not leftSided
    else:
        firstSpace = space / 2

    secondSpace = space - firstSpace

    print('*', ' ' * int(firstSpace), x, ' ' * int(secondSpace), '*', sep='')

print((maxLength + 2) * '*')
