import sys

n, m, k = map(int, sys.stdin.readline().rstrip().split())

if m >= n and k >= n:
    print("yes\n")
else:
    print("no\n")
