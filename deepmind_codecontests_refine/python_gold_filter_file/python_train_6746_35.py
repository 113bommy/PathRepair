import bisect

n = int(input())
a = [int(input()) for _ in range(n)]

LIS = [a[-1]]
for i in range(n - 2, -1, -1):
    if a[i] >= LIS[-1]:
        LIS.append(a[i])
    else:
        LIS[bisect.bisect_right(LIS, a[i])] = a[i]

print(len(LIS))