#!/usr/bin/env python3

if __name__ == '__main__':
    x = [int(x) for x in input().split()]
    x.sort()
    print(x[2] - x[1])

