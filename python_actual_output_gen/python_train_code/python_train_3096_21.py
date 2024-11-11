n = int(input())
if n % 2:
    print(0)
else:
    a = [2, 4, 1]
    b = [3, 4, 2, 1]
    c = [1, -1]
    print((1 + a[n % 3] + b[n % 4] + c[n % 2]) % 5)