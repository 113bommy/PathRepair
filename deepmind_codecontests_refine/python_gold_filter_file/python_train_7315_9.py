#!/usr/bin/env python3


def sol():
    """if array is not reverse sorted, it works"""
    n = int(input())
    a = list(map(int, input().split()))

    if len(set(a)) == n and a == sorted(a, reverse=True):
        print('NO')
    else:
        print('YES')


def main():
    T = int(input())
    for t in range(T):
        sol()


if __name__ == "__main__":
    main()
