import math

n, k = map(int, input().split())
tmp = list(map(int, input().split()))
a = list(set(tmp))
a.sort()
count, pos, len = 0, 0, len(a)
# print(a[2])
while k > 0:
    if pos == len:
        print("0")
    else:
        print(a[pos] - count)
        count = a[pos]
        pos += 1
    k -= 1

