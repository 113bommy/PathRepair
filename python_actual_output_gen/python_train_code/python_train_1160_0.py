import sys


def inp():
    return sys.stdin.readline().rstrip('\n').encode('utf8')


def mpint():
    return map(int, sys.stdin.readline().split(' '))


def itg():
    return int(sys.stdin.readline())


# ############################## import
# ############################## main

for __ in range(itg()):
    n, x = mpint()
    arr = tuple(mpint())
    c = arr.count(x)
    s = sum(arr)
    if c == n:
        print(0)
    elif c or s == x == 0 or (s // n == x):
        print(1)
    else:
        print(2)
# Please check!
