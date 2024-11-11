from math import ceil, sqrt

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())

        if n == 1:
            print(2)
            print(0, 1)
            continue

        d = set()

        for x in range(1, ceil(sqrt(n))):
            d.add(n // x)

        tmp = set()

        for x in d:
            tmp.add(n // x)

        d |= tmp

        d.add(0)

        print(len(d))
        print(*sorted(d))