n, k = map(int, input().split())
a = list(map(int, input().split()))

i = 0
x = 0
h = 0
for j in range(k):
    y = n // a[j]
    if h < y * a[j]:
        h = y * a[j]
        x = y
        i = j + 1
print("%d %d" % (i, x))
