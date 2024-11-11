def answer(a, b, c, d, e, f):
    if c == 0 and d > 0:
        return "Ron"
    if a == 0 and b > 0 and d > 0:
        return "Ron"
    if e == 0 and f > 0 and b > 0 and d > 0:
        return "Ron"
    if b * d * f > a * c * e:
        return "Ron"
    return "Herm"


A, B, C, D, E, F = [int(i) for i in input().split()]
print(answer(A, B, C, D, E, F))
