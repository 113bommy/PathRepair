n, a, b, c = map(int, input().split())
if n % 4 == 3:
    print(min(a, b + c), c * 3, 7 * c)
elif n % 4 == 2:
    print(min(2 * a, b, c * 2))
elif n % 4 == 1:
    print(min(3 * a, a + b, c))
else:
    print(0)