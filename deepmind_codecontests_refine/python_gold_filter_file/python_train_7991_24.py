import math
n,k = map(int,input().split())
a = list(map(int,input().split()))

l = 0
r = 10**9
while r - l > 1:
    m = (l+r) // 2
    cnt = 0
    for i in a:
        cnt += math.ceil(i / m) - 1
    if cnt <= k:
        r = m
    else:
        l = m
print(l+1)
