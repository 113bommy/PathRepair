import math
from sys import stdin
from math import ceil

if __name__ == '__main__':
    numbers = list(map(int, input().split()))
    n = numbers[0]
    m = numbers[1]
    floors = []
    for i in range(m):
        floors.append(tuple(map(int, input().split())))

    rez = set()
    for i in range(1,100):
        ok = True
        for ki, fi in floors:
            if (ki + i - 1) // i != fi:
                ok = False
                break
        if ok:
            rez.add((n + i - 1) // i)

    if len(rez) == 1:
        x = rez.pop()
        print(x)
    else:
        print("-1")

