def getsum(n):
    return ((1 << (2*n)) - 1) // 3

def b(n, k):
    l = n - 1
    r = max(0, l - 41)
    while True:
        mid = (l + r) // 2
        count = getsum(n - mid)
        if count <= k:
            l = mid
        else:
            r = mid
        if l - r <= 1:
            break
        del count
    g = getsum(n - r)
    if g < k:
        del g
        return None
    elif g == k:
        del g
        return r
    return l        


t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    min_side = b(n, k)
    if min_side is None:
        print('NO')
        continue
    k -= getsum(n - min_side)
    if n == 2 and min_side == 1 and k == 2:
        print('NO')
        continue
    num_squares = (1 << (n - min_side)) * 2 - 1
    if k >= num_squares:
        print('YES ' + str(min_side - 1))
    else:
        print('YES ' + str(min_side))