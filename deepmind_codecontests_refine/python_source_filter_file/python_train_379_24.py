import configparser
import math
import sys


input = sys.stdin.readline


def main():

    n = int(input())
    a = [int(x) for x in input().split(' ')]


    i = 1
    ans = 0
    for p in a:
        ans += abs(p - i)
        i += 2

    i = 2
    ans2 = 0
    for p in a:
        ans2 += abs(p - i)
        i += 2

    print(min(ans, ans2))


if __name__ == '__main__':
    main()
