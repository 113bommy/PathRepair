import math

def can_pack(m, b):
    global n, k
    cnt = 0
    if b[-1] > m:
        return False
    p1 = 0
    p2 = n - 1
    while p1 < p2:
        if b[p2] + b[p1] <= m:
            p1 += 1
            p2 -= 1
        else:
            p2 -= 1
        cnt += 1
    if p1 == p2:
        cnt += 1
    return cnt <= k


n, k = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
l = 1
r = 10 ** 9
while l != r - 1:
    m = (l + r) // 2
    if not can_pack(m, b):
        l = m
    else:
        r = m
print(r)