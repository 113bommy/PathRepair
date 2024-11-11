def isprime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def main():
    N = int(input())
    PRIMES = [i * 10 + 1 for i in range(137) if isprime(i * 10 + 1)]
    print(' '.join(map(str, PRIMES[:N])))

main()
