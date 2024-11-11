n = int(input())
a = list(map(int, input().split()))

length = 1
for i in range(1, n):
    if a[i] <= a[i-1]: break
    length += 1
l = [0] * n
for i in range(length):
    l[i] = length - i - 1

length = 1
for i in range(n-2, -1, -1):
    if a[i] <= a[i+1]: break
    length += 1
r = [0] * n
for i in range(n-1, n-1-length, -1):
    r[i] = length - n + i

res = []
lo, hi = 0, n-1
last = 0
while lo <= hi:
    if a[lo] <= last and a[hi] <= last: break
    if a[lo] == a[hi]:
        if l[lo] >= r[hi]:
            res.append('L')
            last = a[lo]
            lo += 1
        else:
            res.append('R')
            last = a[hi]
            hi -= 1
    elif a[lo] < a[hi]:
        if a[lo] > last:
            res.append('L')
            last = a[lo]
            lo += 1
        elif a[hi] > last:
            res.append('R')
            last = a[hi]
            hi -= 1
    else:
        if a[hi] > last:
            res.append('R')
            last = a[hi]
            hi -= 1
        elif a[lo] > last:
            res.append('L')
            last = a[lo]
            lo += 1


print(len(res))
print(''.join(res))
