# Even Odds
from math import ceil
s = input()

n, k = [int(i) for i in s.split()]


def isEven(x):
    if (x % 2 == 0):
        return True
    else:
        return False

# determine the base which is the greatest odd number
if (isEven(n)):
    base = n - 1
    baseIndex = n / 2
else:
    base = n
    baseIndex = ceil(n / 2)

if (k <= baseIndex):
    print(k + k - 1)
else:
    print(k + k - 1 - base)
