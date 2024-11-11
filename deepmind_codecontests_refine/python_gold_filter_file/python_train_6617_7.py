import sys
from os import path
if (path.exists('input.txt') and path.exists('output.txt')):
    sys.stdout = open('output.txt', 'w')
    sys.stdin = open('input.txt', 'r')

def main():
    n, n1, n2 = (int(i) for i in input().split())
    l = sorted([int(i) for i in input().split()], reverse=True)

    if n1 > n2: n1, n2 = n2, n1
    ans = sum(l[:n1]) / n1 + sum(l[n1:n1 + n2]) / n2
    print(ans)


main()