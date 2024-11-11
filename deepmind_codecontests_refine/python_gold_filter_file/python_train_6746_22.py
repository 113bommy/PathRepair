#134_E
import bisect
n=int(input())
a=[int(input()) for _ in range(n)][::-1]

LIS = [a[0]]
for i in range(1, n):
    if a[i] >= LIS[-1]:
        LIS.append(a[i])
    else:
        LIS[bisect.bisect_right(LIS, a[i])] = a[i]

print(len(LIS))