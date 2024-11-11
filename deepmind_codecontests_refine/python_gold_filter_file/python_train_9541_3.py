a = input()
if a == a[::-1]:
    print(a)
else:
    x = a[1: 10 ** 4]
    b = x[::-1] + a
    print(b)