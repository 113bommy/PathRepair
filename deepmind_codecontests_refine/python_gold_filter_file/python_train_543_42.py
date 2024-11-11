n = int(input())
for i in range(n):
    n = int(input())
    final = 0
    z = (n-1) / 2
    while z != 0:
        final += (n * 4 - 4) * z
        z -= 1
        n -= 2
    print(int(final))