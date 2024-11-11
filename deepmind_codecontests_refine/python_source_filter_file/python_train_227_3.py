import sys, collections

tc = int(sys.stdin.readline())
for _ in range(tc):
    n = int(sys.stdin.readline())
    arr = list(map(int, sys.stdin.readline().split()))
    pre = -1
    suf = n
    for i in range(n):
        if arr[i] > i:
            break
        pre = i
    for i in range(n - 1, -1, -1):
        if arr[i] > (n - 1) - i:
            break
        suf = i
    print('YES' if pre >= suf else 'NO')