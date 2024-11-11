import sys
import math
import bisect

def solve(s):
    n = len(s)
    for i in range(n - 1):
        if s[i+1] <= s[i]:
            return s[0:i] + s[i+1:]
    return s[:-1]

def main():
    n = int(input())
    s = input()
    ans = solve(s)
    print(ans)

if __name__ == "__main__":
    main()
