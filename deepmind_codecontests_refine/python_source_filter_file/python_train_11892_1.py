from sys import stdin, stdout, stderr, exit
from math import log, factorial
import re

# inputf = open('input.txt', 'r')
# outputf = open('output.txt', 'w')


def readil():
    return list(map(int, stdin.readline().strip().split()))


def C(n, k):
    if(n-k >= 0):
        return factorial(n) // factorial(k) // factorial(n-k)
    else:
        return 1

def main():
    n, m, k = readil()
    stdout.write(str((C(n - 1, 2 * k) * C(m - 1, 2 * k)) % 1000000007))

if __name__ == '__main__':
    main()


# inputf.close()
# outputf.close()
