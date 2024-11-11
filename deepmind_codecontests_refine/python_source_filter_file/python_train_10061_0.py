if __name__ == '__main__':
    x = int(input())
    pSieve = [True] * x

    for i in range(2, x):
        if pSieve[i]:
            for j in range(i * i, x, i):
                pSieve[j] = False

    primos = []
    for i in range(2,x):
        if pSieve[i]:
            primos.append(i)

    y = x-1

    for p in primos:
        if x % p == 0:
            y = x - p

    z = y + 1

    for i in primos:
        if i > y:
            break
        d = y - y % i
        if d + i <= x:
            z = min(z, d+1)

    print(i)
