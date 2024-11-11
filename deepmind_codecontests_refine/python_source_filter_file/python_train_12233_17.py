if __name__ == '__main__':
    n = int(input())
    prime = [True] * 1001
    for i in range(2, 1000):
        if prime[i]:
            for j in range(i * i, 1000, i):
                prime[j] = False
            if n % i == 0:
                while n % i == 0:
                    n //= i
                n *= i
    print(n)
