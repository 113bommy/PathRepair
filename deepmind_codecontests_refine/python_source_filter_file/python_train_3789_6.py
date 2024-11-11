from sys import stdin
n, m = list(map(int, stdin.readline().split()))
a = [0] + list(map(int, stdin.readline().split()))
s = 0
for _ in range(m):
    op = list(map(int, stdin.readline().split()))
    if op[0] == 1:
        a[op[1]] = op[2]
    elif op[0] == 2:
        s += op[1]
    else:
        print(a[op[1]] + s)