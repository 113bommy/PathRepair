import sys
read = lambda: list(map(int, sys.stdin.readline().strip().split()))

for _ in range(int(input())):
    n, m = read()
    if n%m == 0:
        print('YES')
    else:
        print('NO')





















