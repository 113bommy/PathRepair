from collections import defaultdict
from sys import stdin

input = stdin.readline

if __name__ == '__main__':
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))

        dct = defaultdict(lambda: 0)

        for i in range(n):
            dct[i + 1 + arr[(i + 1) % n]] += 1

        u = True

        for key, value in dct.items():
            if value > 1:
                u = False
                break

        print('YES' if u else 'NO')