import sys, math

tc = int(sys.stdin.readline())
for _ in range(tc):
    n, d = map(int, sys.stdin.readline().split())
    if d <= n:
        print('YES')
    else:
        temp = int(d ** 0.5) - 1
        min_day = temp + math.ceil(d / (temp + 1))
        print('YES' if min_day <= n else 'NO')
