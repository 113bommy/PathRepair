from math import floor, ceil

n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort(reverse=True)
l = 1
r = max(a)
while r - l > 1:
    c = (l+r)//2
    cnt = 0
    for i in a:
        cnt += max(ceil(i/c) - 1, 0)
    if cnt <= k:
        r = c
    else:
        l = c
print(r)