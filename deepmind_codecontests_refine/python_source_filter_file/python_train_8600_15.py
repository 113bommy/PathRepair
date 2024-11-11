#!/usr/bin/env python3
# -*- coding: utf-8 -*-

def main():
    n = int(input())
    arr = [0, -1, -1, -1, 1, -1, 1, -1, 2, -1, 2, -1]
    for i in range(n):
        a = int(input())
        if (a >= 12):
            print(a // 4 - a % 2)
        else:
            print(arr[a])

if __name__ == "__main__":
    main()
