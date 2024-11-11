import math
import sys

input_ = sys.stdin.readline


def solve3(x, y, p, q):
    if p == q:
        if x == y:
            return 0
        return -1

    if p == 0:
        if x == 0:
            return 0
        return -1

    diff = (q - y % q) % q
    m = (y + diff) / q

    n1 = (x - p * m) / p
    n2 = (m * p - x) / (q - p)
    n = math.ceil(max(n1, n2))

    return diff + n * q


def main():
    t = int(input_())
    solutions = []

    for _ in range(t):
        x, y, p, q = map(int, input_().split())
        solutions.append(solve3(x, y, p, q))

    return solutions

if __name__ == '__main__':
    solutions = main()

    for s in solutions:
        print(s)
