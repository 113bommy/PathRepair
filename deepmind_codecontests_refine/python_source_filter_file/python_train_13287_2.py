n, a, b = map(int, input().split())

l = 0
r = n+1
ans = 0

while r-l > 1:
    m = (r+l) >> 1
    if b//m and a//m and a // m + b // m >= n:
        l = m
    else:
        r = m
print(l)
