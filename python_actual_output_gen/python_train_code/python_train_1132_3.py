t = int(input())
for i in range(t):
    n = int(input())
    l = len(str(n))
    b = 9 * (l-1)
    b += n // (10 ** (l-1))
    print(b)