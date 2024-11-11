n, a, b, c = map(int, input().split())
if n % 4 == 0:
    print(0)
elif n % 4 == 1:
    print(min(3 * a, a + b, c))
elif n % 4 == 2:
    print(min(2 * a, b, 2 * c))
else:
    print(min(a, b + c))