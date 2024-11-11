n, k = map(int, input().split())
a = sorted(list(map(int, input().split())))
f = sorted(list(map(int, input().split())))[::-1]
r = 10**12+1
l = -1
while r - l > 1:
    s = k
    mid = (r + l)//2
    for i, j in zip(a, f):
        if mid < i*j:
            s -= i-mid//j
    if s < 0:
        l = mid
    else:
        r = mid
    print('r:', r, 'l:', l, 'r-l:', r-l)
print(r)
