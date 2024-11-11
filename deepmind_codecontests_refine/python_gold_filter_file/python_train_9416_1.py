from sys import stdin
_data = iter(stdin.read().split('\n'))
input = lambda: next(_data)

n, m, w = map(int, input().split())
a = list(map(int, input().split()))
ub, lb = 2 * 10 ** 9, 0

def check(x):
    u = m
    s = [0] * (n + 1)
    for i in range(n):
        if i > 0:
            s[i] += s[i - 1]
        v = a[i] + s[i]
        if v < x:
            d = x - v
            u -= d
            if u < 0:
                return False
            s[i] += d
            s[min(i + w, n)] -= d
    return True
            

while ub - lb > 1:
    mid = (ub + lb) // 2
    if check(mid):
        lb = mid
    else:
        ub = mid
print(lb)
