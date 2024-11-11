#	!/usr/bin/env python3
#	coding: UTF-8
#	Modified: <19/Feb/2019 08:08:00 PM>


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology (IIIT),Gwalior

#	Question Link
#
#

# ///==========Libraries, Constants and Functions=============///


import sys

inf = float("inf")
mod = 1000000007


def get_array(): return list(map(int, sys.stdin.readline().split()))


def get_ints(): return map(int, sys.stdin.readline().split())


def input(): return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        n, a, b = get_ints()
        if 2 * a < b:
            print(n * a)
        else:
            print(n // 2 * b + (n % 2) * a)


if __name__ == "__main__":
    main()
