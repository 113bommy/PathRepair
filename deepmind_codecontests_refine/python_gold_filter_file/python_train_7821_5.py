n = int(input())
a = [int(x) for x in input().rstrip().split()]

r = a[n - 1]
for i in reversed(range(0, n-1)):
    if a[i] < a[i + 1]:
        r += a[i]
    else:
        if a[i + 1] > 0:
            r += a[i + 1] - 1
        a[i] = max(0, a[i + 1] - 1)

print(r)

