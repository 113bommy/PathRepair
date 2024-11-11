import math
import sys


def is_prime(n, p):
    if n % 2 == 0 and n > 2:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if i > p: break
        if n % i == 0:
            return False
    return True


def main():
    p, y = map(int, sys.stdin.readline().split())

    highest = y
    if y % 2 == 0:
        highest -= 1
    while highest >= p:
        if is_prime(highest, p):
            print(highest)
            return
        highest -= 2

    print(-1)


if __name__ == '__main__':
    main()
