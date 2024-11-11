def isPrime(n):
    if (n <= 1):
        return False
    if (n <= 3):
        return True
    if (n % 2 == 0 or n % 3 == 0):
        return False
    i = 5
    while (i * i <= n):
        if (n % i == 0 or n % (i + 2) == 0):
            return False
        i = i + 6

    return True


num=int(input())
if (isPrime(num)==True):
    print(1)
elif num%2==0 or isPrime(num-3)==True:
    print(2)
else:
    print(3)