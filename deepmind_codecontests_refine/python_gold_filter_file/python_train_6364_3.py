n = int(input())
a = [int(i) for i in input().split()]
mi = 10 ** 8
x = -1
for i in range(1, 111):
    s = 0
    for j in range(n):
        if not i - 1 <= a[j] <= i + 1:
            if a[j] < i - 1:
                z = i - 1 - a[j]
            else:
                z = a[j] - i - 1
            s += z
    if s < mi:
        mi = s
        x = i
print(x, mi)
