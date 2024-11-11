from heapq import heappop, heappush

n = int(input())
a = list(map(int, input().split()))

acc_l = [0]*n
hq = []
total = 0
for i, x in enumerate(a):
    cnt = 1
    minus = 0
    while hq and -hq[0][0] > x:
        p = heappop(hq)
        minus += p[0] * p[1]
        cnt += 1

    total += minus + x * cnt
    acc_l[i] = total
    heappush(hq, (-x, cnt))

acc_r = [0]*n
hq = []
total = 0
for i, x in zip(range(n-1, -1, -1), reversed(a)):
    cnt = 1
    minus = 0
    while hq and -hq[0][0] > x:
        p = heappop(hq)
        minus += p[0] * p[1]
        cnt += 1

    total += minus + x * cnt
    acc_r[i] = total
    heappush(hq, (-x, cnt))

high_i = 0
max_v = 0
for i in range(n):
    if acc_l[i] + acc_r[i] - a[i] > max_v:
        high_i = i
        max_v = acc_l[i] + acc_r[i] - a[i]

min_v = a[high_i]
for i in range(high_i-1, -1, -1):
    if a[i] > min_v:
        a[i] = min_v
    else:
        min_v = a[i]

min_v = a[high_i]
for i in range(high_i+1, n):
    if a[i] > min_v:
        a[i] = min_v
    else:
        min_v = a[i]

print(*a)
