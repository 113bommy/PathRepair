# python3


def AND(x, y): return x & y
def OR(x, y): return x | y
def XOR(x, y): return x ^ y


f1 = AND
f2 = OR
f3 = XOR


def main():
    a, b, c, d = tuple(int(input()) for __ in range(4))
    one = f3(f1(a, b), f2(c, d))
    two = f2(f3(b, c), f1(a, d))
    print(f1(one, two))




main()
