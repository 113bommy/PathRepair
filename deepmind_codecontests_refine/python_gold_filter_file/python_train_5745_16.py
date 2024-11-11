# from sys import stdin
# input = stdin.buffer.readline
for _ in range(int(input())):
    n, m, k = map(int, input().split())
    *a, = map(int, input().split())
    for i in range(n - 1):
        m += max(a[i] - max(0, a[i + 1] - k), a[i] - a[i + 1] - k)
        if m < 0:
            print('NO')
            break
    else:
        print('YES')