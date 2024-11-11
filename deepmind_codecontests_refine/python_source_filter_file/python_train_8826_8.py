import bisect

n = int(input())
k = sorted(map(int, input().split()))

hist = []
count = 0
for i in range(n):
    count += 1
    if i == n - 1 or k[i] != k[i + 1]:
        hist.append(count)
        count = 0
hist.sort()

sumh = [0]
for i in range(len(hist)):
    sumh.append(sumh[-1] + hist[i])

def ok(h, d):
    i = bisect.bisect_left(hist, h)
    s = sumh[i] + h * (len(hist) - i)
    return s >= h * d

def binary_search(d):
    lo, hi = 0, 10 ** 10
    while hi - lo > 1:
        mid = (lo + hi) // 2
        if ok(mid, d):
            lo = mid
        else:
            hi = mid
    return lo

for d in range(1, n + 1):
    print(binary_search(d))
