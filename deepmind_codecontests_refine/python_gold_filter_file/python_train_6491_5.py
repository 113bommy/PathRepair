from collections import *


def solve():
    global small
    small2, num = deque(str(small)), 1

    for i in range(len(small2) - 1, -1, -1):
        if small2[i] != '9':
            for j in range(9, int(small2[i]), -1):
                if small + ((j - int(small2[i])) * num) <= p:
                    small2[i] = str(j)
                    small = int(''.join(small2))
                    break
        num *= 10
    for i in range(len(p1) - 1, len(small2) - 1, -1):
        for j in range(9, 0, -1):
            if small + (j * num) <= p:
                small2.appendleft(str(j))
                small = int(''.join(small2))
                break
        num *= 10
    return small


p, d = map(int, input().split())
small, p1 = p - d, list(str(p))

if d == 0 or p1.count('9') == len(p1):
    print(p)
else:
    print(solve())
