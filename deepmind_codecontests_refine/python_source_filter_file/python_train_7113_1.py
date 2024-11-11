n, k = [int(x) for x in input().split()]
s = int(n * (k - 1) / k)
if n - s <= 1:
    print('n')
else:
    for i in range(s, n):
        num = 0
        j = 0
        while (k ** (j + 1) - 1)/(k - 1) < i:
            j += 1
        for b in range(j + 1):
            num += int(i / (k ** b))
        if num >= n:
            print(i)
            break