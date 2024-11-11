#!/usr/bin/env python
# -.- coding: utf-8 -.-


def main():
    a, b = [int(item) for item in input().strip().split(" ")]
    count = 0
    while (a % b) != 0:
        count += a / b
        a, b = b, a % b
        if a < b:
            a, b = b, a
    count += a / b
    print(int(count))


if __name__ == "__main__":
    main()
