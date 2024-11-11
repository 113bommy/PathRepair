import sys

t = int(input())
for i in range(t):
    n, k1, k2 = map(int, sys.stdin.readline().split())
    a = [int(i) for i in sys.stdin.readline().split()]
    b = [int(i) for i in sys.stdin.readline().split()]
    if max(a) > max(b):
        sys.stdout.write("YES\n")
    else:
        sys.stdout.write("NO")