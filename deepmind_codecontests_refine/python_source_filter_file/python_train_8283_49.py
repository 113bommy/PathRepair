import itertools
def op(a, b, x):
    if x == 0:
        return a | b
    elif x == 1:
        return a ^ b
    else:
        return a & b

def main():
    a = int(input())
    b = int(input())
    c = int(input())
    d = int(input())

    p = (2, 0, 1)
    e = op(a, b, p[0])
    f = op(c, d, p[1])
    g = op(b, c, p[2])
    h = op(a, d, p[0])

    i = op(e, f, p[2])
    j = op(g, h, p[1])
    k = op(i, j, p[0])

    print(k)

main()
