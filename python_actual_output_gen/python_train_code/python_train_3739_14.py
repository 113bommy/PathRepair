n = 0

def add(x, y):
    m = int(pow(-1, x))
    return m * (n // y)

n = int(input())
a = n

a += add(1, 2)
a += add(1, 3)
a += add(1, 5)
a += add(1, 7)

a += add(0, 2 * 3)
a += add(0, 2 * 5)
a += add(0, 2 * 7)
a += add(0, 3 * 5)
a += add(0, 3 * 7)
a += add(0, 5 * 7)

a += add(1, 2 * 3 * 5)
a += add(1, 2 * 3 * 7)
a += add(1, 2 * 5 * 7)
a += add(1, 3 * 5 * 7)

a += add(0, 3 * 5 * 7)

print(a)