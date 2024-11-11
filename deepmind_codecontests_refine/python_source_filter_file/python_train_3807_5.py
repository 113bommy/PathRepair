from math import sqrt

def is_prime(n):
    for i in range(2, int(sqrt(n))):
        if n%i == 0:
            return False
    return True

def tax(n):
    if n == 2 or n == 5:
        return 1
    elif n%2 == 0:
        return 2
    else:
        if is_prime(n):
            return 1
        elif is_prime(n-2):
            return 2
        else:
            return 3

n = int(input())
print(tax(n))



