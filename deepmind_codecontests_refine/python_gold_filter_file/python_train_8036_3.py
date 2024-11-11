import fractions

t = int(input())
for i in range(t):
    a, b, k = map(int, input().split())
    if a > b:
        a, b = b, a
    g = fractions.gcd(a, b)
    a //= g
    b //= g
    if (k - 1) * a + 1 < b:
        print("REBEL")
    else:
        print("OBEY")
