def main():
    from math import gcd
    n, a, b, p, q = map(int, input().split())
    if p < q:
        a, b, p, q = b, a, q, p
    print(n // a * p + (n // b - n * gcd(a, b) // a // b) * q)


if __name__ == '__main__':
    main()
