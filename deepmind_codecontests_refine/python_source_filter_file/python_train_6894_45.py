import sys

input = lambda: sys.stdin.readline().rstrip()


for i in range(int(input())):
    n, m = map(int, input().split())
    if n % 2 == m % 2:
        print("YES")
    else:
        print("NO")
