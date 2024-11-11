def winorfreeze(n):
    factors = []
    i = 2
    while i * i <= n:
        while n % i == 0:
            factors.append(i)
            n //= i
            if len(factors) == 3:
                return factors[0] * factors[1]
        i += 1

    if n != 1:
        factors.append(n)

    if len(factors) <= 1:
        return 0
    elif len(factors) == 3:
        return factors[0] * factors[1]
    else:
        return None


def main():
    n = int(input())
    ans = winorfreeze(n)
    if ans is None:
        print(2)
    else:
        print(1)
        print(ans)


if __name__ == "__main__":
    main()
