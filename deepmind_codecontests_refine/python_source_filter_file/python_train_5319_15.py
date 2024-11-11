n, m = int(input()), int(input())
a, b = [int(i) for i in input().split()], [int(i) for i in input().split()]

def check(t):
    for i in range(n):
        t -= (t + m) / a[i]
        if t < 0:
            return 0
        t -= (t + m) / b[(i + 1) % n]
        if t < 0:
            return 0
    return 1

l, r = 0, 10 ** 9
if not check(r):
    print(-1)
else:
    for i in range(300):
        mid = (l + r) / 2
        if check(mid):
            r = mid
        else:
            l = mid
    print(l)
