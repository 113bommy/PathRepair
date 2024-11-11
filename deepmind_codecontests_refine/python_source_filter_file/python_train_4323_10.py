import sys
import math
import bisect

def main():
    n = int(input())
    A = []
    for i in range(n):
        val = 1
        while len(A) and A[-1] == val:
            A.pop()
            val <<= 1
        A.append(val)
    print(' '.join(list(str(a) for a in A)))

if __name__ == "__main__":
    main()
