def arr_2d(n):
    return [[str(x) for x in stdin.readline().split()] for i in range(n)]


def flip(x):
    if x == '<=':
        x = '>'
    elif x == '>=':
        x = '<'
    elif x == '<':
        x = '>='
    else:
        x = '<='
    return x


from sys import stdin
from random import randint

n, mi, ma = int(input()), -2000000000, 2000000000
a = arr_2d(n)
for op, num, ans in a:
    num = int(num)
    if ans == 'N':
        op = flip(op)
    if op == '>=':
        mi = max(num, mi)
    elif op == '>':
        mi = max(num + 1, mi)
    elif op == '<=':
        ma = min(num, ma)
    else:
        ma = min(num, ma)

print(randint(mi, ma) if ma >= mi else 'Impossible')
