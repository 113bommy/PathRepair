l, r = [int(i) for i in input().split()]
i2 = i3 = 0
counter = 0
while (2 ** i2) * (3 ** i3) < r:
    while (2 ** i2) * (3 ** i3) < r:
        counter += 1 if (2 ** i2) * (3 ** i3) >= l else 0
        i3 += 1
    i3 = 0
    i2 += 1
print(counter)