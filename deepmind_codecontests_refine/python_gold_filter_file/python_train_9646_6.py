import sys
import math


def can_match(inp, square):
    operations = 0
    inp_idx = 0
    ok = True
    for digit in square:
        while inp_idx < len(inp) and digit != inp[inp_idx]:
            inp_idx = inp_idx + 1
            operations = operations + 1
        if inp_idx == len(inp):
            ok = False
            break
        inp_idx = inp_idx + 1
    if ok:
        return (operations + (len(inp) - inp_idx - 1))
    return -1


data = sys.stdin.readlines()[0]
square = int(data)
sol = -1
while square > 0:
    square = math.floor(math.sqrt(square)) ** 2
    result = can_match(data, str(square))
    if result != -1:
        sol = result
        break
    square = square - 1
print(sol)
