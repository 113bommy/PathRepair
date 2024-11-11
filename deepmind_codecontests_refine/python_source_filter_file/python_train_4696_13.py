from math import gcd
from functools import reduce
h, w, x, y = map(int, input().split())
a = str(x) + ':' + str(y)
def solve(ratio):
    numbers = [int(i) for i in ratio.split(':')]
    denominater = reduce(gcd, numbers)
    solved = [i / denominater for i in numbers]
    return ':'.join(str(int(i)) for i in solved)
a = solve(a)
x, y = map(int, a.split(':'))
print(min(w // x, h // y))
