# https://codeforces.com/problemset/problem/743/B

# Problem
# Big O:
# Time complexity:
# Space complexity:


def sequenceLengthAtStep(step):
    if step == 1:
        return 1
    return sequenceLengthAtStep(step - 1) * 2 + 1


def elementAtPos(pos, steps):
    sequenceLength = sequenceLengthAtStep(steps)
    integer = 1
    posOfFirstDigit = 1
    while posOfFirstDigit < sequenceLength:
        elementModulus = posOfFirstDigit * 2
        if (pos - posOfFirstDigit) % elementModulus == 0:
            return integer
        integer += 1
        posOfFirstDigit *= 2

    return -1


# Read input
steps, pos = (int(x) for x in input().split())
print(elementAtPos(pos, steps))
