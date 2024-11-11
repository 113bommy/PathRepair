#1398C
import sys
def i():
    return sys.stdin.readline()[:-1]

def listDigits():
    return list(map(lambda x: int(x) - 1,i()))

cases = int(i())
for x in range(cases):
    n = int(i())
    digits = listDigits()

    goodSubArrays = 0
    sums = {}
    for y,digit in enumerate(digits):
        if digit == 0:
            goodSubArrays += 1
        if -digit in sums.keys():
            goodSubArrays += sums[-digit]
        newSums = {}
        for key in sums:
            if -50 < key+digit < 50:
                newSums[key+digit] = sums[key]
        if digit in newSums.keys():
            newSums[digit] += 1
        else:
            newSums[digit] = 1
        sums = newSums
    print(goodSubArrays)
