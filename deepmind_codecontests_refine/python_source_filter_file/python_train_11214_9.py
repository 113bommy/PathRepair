import sys
n, *a = [int(s) for s in sys.stdin.read().split()]
if n == 1:
    print(-1)
elif n == 2 and a[0] == a[1]:
    print(-1)
else:
    print(1)
    print(a.index(min(a)))
