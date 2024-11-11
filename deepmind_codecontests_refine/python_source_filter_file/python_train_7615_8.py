t = int(input())


for _ in range(t):
    n, k = [ int(x) for x in input().split() ]
    resultado = 0 

    while n > 0:
        if n % k == 0:
            n /= k
            resultado += 1
        else:
            m = n % k
            n -= m
            resultado += m

    print(resultado)