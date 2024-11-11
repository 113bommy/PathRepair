import math

def check(x):
    k = 0
    global h, a, b
    for i in h:
        if x * b < i:
            k += math.ceil((i - x * b) / (a - b))
    return k <= x


n, a, b = map(int, input().split())
h = []
for i in range(n):
    h.append(int(input()))
l = -1
r = max(h) // b
while r - l > 1:
    m = (l + r) // 2
    if check(m):
        r = m
    else:
        l = m
print(r)