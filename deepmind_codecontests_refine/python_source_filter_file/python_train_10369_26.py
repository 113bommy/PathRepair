import sys
import math


def is_unlucky(year, x, y):
    max_a = int(math.log(year, x))
    max_b = int(math.log(year, y))

    for a in range(max_a + 1):
        for b in range(max_b + 1):
            if x ** a + y ** b == year:
                return True
    return False


def main():
    x, y, l, r = list(map(int, input().split()))
    unlucky = []
    p = 1
    #unlucky.append(l - 1)
    while True:
        if p > r:
            break
        q = 1
        while True:
            if p + q > r:
                break
            if p + q >= l:
                unlucky.append(p + q)
            q *= y
        p *= x
    #unlucky.append(r + 1)
    unlucky = sorted(unlucky)
    max_interval = 0
    for i in range(len(unlucky) - 1):
        max_interval = max(max_interval, unlucky[i + 1] - unlucky[i] - 1)
    print(max_interval)


if __name__ == "__main__":
    main()
