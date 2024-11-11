def eratosthenes(n):                      # n - число, до которого хотим найти простые числа
    sieve = list(range(n + 1))
    #print(sieve)
    sieve[1] = 0                          # без этой строки итоговый список будет содержать единицу
    prime = []
    for i in sieve:
        if i > 0:
            prime.append(i)
            for j in range(i * i, len(sieve), i):
                sieve[j] = 0
    #return sieve
    return prime


n = int(input())
s = 0
p = eratosthenes(100000)


if n % 2 == 0:
    print(n // 2)
else:
    for i in p:
        if n % i == 0:
            print(1 + (n - i) // 2)
            break
    print(1)
