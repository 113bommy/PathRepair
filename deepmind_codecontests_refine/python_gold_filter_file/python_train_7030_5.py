#	!/bin/env python3
#	coding: UTF-8


#	✪ H4WK3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

#	Question Link
#	https://codeforces.com/problemset/problem/665/C
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
    s = list(input().rstrip())
    for i in range(1, len(s)):
        if s[i] == s[i-1]:
            if s[i-1] != 'z':
                s[i] = 'z'
                if i < len(s)-1 and s[i] == s[i+1]:
                    s[i] = 'y'
                    if s[i] == s[i-1]:
                        s[i] = 'x'
            else:
                s[i] = 'a'
                if i < len(s)-1 and s[i] == s[i+1]:
                    s[i] = 'b'
    print(*s, sep='')
    print()


if __name__ == "__main__":
    main()
