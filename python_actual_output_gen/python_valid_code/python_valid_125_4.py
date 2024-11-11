k = int(input())
b = [4, 8, 15, 16, 23, 42]
a = [int(x) for x in input().split()]
c = [0, 0, 0, 0, 0, 0]
for i in range(k):
    n = b.index(a[i])
    if a[i] == b[0]:
        c[0] += 1
    else:
        if c[n - 1] >= c[n]:
            c[n - 1] -= 1
            c[n] += 1
print(k - c[5] * 6)
