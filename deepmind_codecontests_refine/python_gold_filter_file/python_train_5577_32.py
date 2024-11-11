n, a, b, c = map(int, input().split())
if n % 4 == 0:
    print(0)
elif n % 4 == 1:
    ans = min(c, 3 * a, a + b)
    print(ans)
elif n % 4 == 2:
    ans = min(2 * a, b, 2 * c)
    print(ans)
else:
    ans = min(a, c + b, 3 * c)
    print(ans)
