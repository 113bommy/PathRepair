#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 14/Dec/19 11:01:22 PM


import sys


def main():
    for tc in range(int(input())):
        s = list(input())
        ans = []
        for i in range(len(s) - 2):
            x = "".join(s[i : i + 3])
            y = ""
            if i < len(s) - 4:
                y = "".join(s[i + 2 : i + 5])
            # print(x, y)
            if x == "one":
                ans.append(i + 2)
                s[i + 1] = "#"
            elif x == "two":
                if y == "one":
                    ans.append(i + 3)
                    s[i + 2] = "#"
                else:
                    ans.append(i + 2)
                    s[i + 1] = "#"

        print(len(ans))
        print(*ans)


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
