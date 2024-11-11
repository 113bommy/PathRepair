import sys
f = sys.stdin
m, n = (int(number) for number in f.readline().split())
b = [int(number) for number in f.readline().split()]
a = [int(number) for number in f.readline().split()]
b.sort()
a.sort()
mx = a[0] * b[0]
if mx < a[n - 1] * b[m - 1]:
    mx = max(mx, a[n - 1] * b[m - 2])
else:
    mx = max(a[0] * b[1], a[n - 1] * b[m - 1])
if mx < 0:
    if a[0] > 0:
        mx = a[0] * b[m - 2]
    else:
        mx = a[n - 1] * b[1]
print(mx)
