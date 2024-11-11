import configparser
import sys
input = sys.stdin.readline


def ceil_div(x, y):
    return -(-x // y)

def can(k, n):

    if k == 0:
        return False

    org = n
    i = 0

    while n > 0:
        take_off = min(n, k)

        n -= take_off
        i += take_off
        n -= (n//10)

    return i >= ceil_div(org, 2)

def main():
    n = int(input())

    pos = -1

    for i in range(20, -1, -1):

        jump = (1 << i)

        if not can(pos+jump, n):
            pos += jump

    print(pos+1)



if __name__ == '__main__':
    main()
