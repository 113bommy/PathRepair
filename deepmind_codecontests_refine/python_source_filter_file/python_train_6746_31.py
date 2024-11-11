import bisect
n = int(input())
a = [int(input()) for _ in range(n)]

b = [a[-1]]
for i in range(n - 2, -1, -1):
    if b[-1] <= a[i]:
        b.append(a[i])
    else:
        b[bisect.bisect_left(b, a[i])] = a[i]

print(len(b))