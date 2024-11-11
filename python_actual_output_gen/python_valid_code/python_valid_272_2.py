def ok(m):
    c = 1
    tmp = m
    for w in W:
        if tmp > w:
            tmp -= w
        else:
            c += 1
            tmp = m - w
    return k >= c

n, k = map(int, input().split())
W = [int(input()) for i in range(n)]

left = max(W)
right = sum(W)
while left+1 < right:
    mid = (left+right) // 2
    if ok(mid):
        right = mid
    else:
        left = mid
print(left)
