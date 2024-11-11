import sys
import math

# input = lambda: sys.stdin.readline().rstrip()
for i in range(int(input())):
    s = input()
    if "1" in s and "0" in s:
        if s[0] == "1":
            for i in range(len(s)):
                print("10", end='')
        else:
            for i in range(len((s))):
                print("01", end='')
        print()
    else:
        print(s)
