from math import factorial as f

n = int(input())
if n == 3:
    print(24)
else:
    print(2 * 4 * 3 * (4 ** (2 * n - n - 2 - 1)) + (n - 4) * 4 * 3 * 3 * (4 ** (n - 4)))