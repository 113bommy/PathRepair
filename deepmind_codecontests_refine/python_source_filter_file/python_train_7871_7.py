import sys
import heapq
import math
from enum import Enum

class Status:
    UNTOUCHED = 1
    FLIPPED = 2
    ONE = 3
    ZERO = 4

bits = [Status.UNTOUCHED]*10
lines = sys.stdin.read().splitlines()

n = int(lines[0])

andNum = 1023
orNum = 0
xorNum = 0
for i in range(1, n+1):
    # print(andNum)
    # print(orNum)
    # print(xorNum)

    operation, num = lines[i].split(' ')
    num = int(num)
    # print(num)
    # print('----')
    if operation == '|':
        andNum=andNum|num
        orNum=orNum|num
        xorNum=xorNum&(orNum^1023)
    elif operation == '&':
        andNum=andNum&num
        orNum=orNum&num
        xorNum=xorNum&num
    else:
        # Flip all ones to zeroes and flip untouched
        # All bits that were set to 1 in OR mask and 1 in num, should be set to 0 in AND mask
        # All bits that were set to 0 in AND mask and 1 in num, should be set to 1 in OR mask
        # All those bits that were not set to 0 in AND mask and not set to 1 in OR mask should be set to 1 in xor MASK
        oldAndNum=andNum
        oldOrNum=orNum
        andNum=andNum^((orNum|(andNum^1023))&num)
        orNum=orNum^((oldAndNum^1023)|(orNum)&num)
        xorNum=xorNum^(oldAndNum&(oldOrNum^1023)&num)

# OR
print(3)
print('& '+str(andNum))
print('| '+str(orNum))
print('^ '+str(xorNum))



