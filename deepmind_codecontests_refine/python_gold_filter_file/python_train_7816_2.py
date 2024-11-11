import os
import sys
import math

def main():
    n = int(input())
    s = input()
    assert len(s) == n
    if n>26:
        print("Yes")
        sys.exit(0)
    elif n == 1:
        print("Yes")
        sys.exit(0)
    a = {}
    for i in s:
        a[i] = 0
    for i in s:
        a[i]+=1
    for i in a:
        if a[i]>1:
            print("Yes")
            sys.exit(0)
    print("No")


if __name__ == '__main__':
    main()
