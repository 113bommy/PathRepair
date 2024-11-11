def main():
    from math import sqrt, floor
    n = int(input())
    encrypted = input()
    divisors = [1]

    for i in range(2, floor(sqrt(n)) + 1):
        if n % i == 0:
            divisors += [i] if i ** 2 == n else [i, n // i]

    if n > 2:
        divisors += [n]

    divisors.sort()

    for d in divisors:
        encrypted = encrypted[:d][::-1] + encrypted[d:]

    print(encrypted)


if __name__ == '__main__':
    main()
