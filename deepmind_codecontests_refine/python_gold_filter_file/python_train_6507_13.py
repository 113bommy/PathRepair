# @author: guoyc
# @date: 2018/7/20

lines = []

import sys

N = 0

for line in sys.stdin:
    line = line.strip()
    N = max(N, len(line))
    lines.append(line)

print('*' * (N + 2))


def p(line, tol):
    ret = []
    ret.append('*')
    total = N - len(line)
    left = total >> 1
    right = total - left
    if not tol:
        left, right = right, left
    ret.append(' ' * left)
    ret.append(line)
    ret.append(' ' * right)
    ret.append('*')
    return left == right, ''.join(ret)


tol = True

for l in lines:
    x, s = p(l, tol)
    print(s)
    if not x:
        tol = not tol

print('*' * (N + 2))
