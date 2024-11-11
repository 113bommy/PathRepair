k, n, w = [int(x) for x in input().split()]

total = k * ((w * (w + 1)) // 2)

if n != total:
    borrow = abs(n - total)
    print(borrow)
else:
    print('0')