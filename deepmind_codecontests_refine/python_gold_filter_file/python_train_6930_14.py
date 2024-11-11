def isprime(num):
    div = 0
    for i in range(1, num + 1):
        if num % i == 0:
            div += 1
    return div == 2

def findInto(num):
    if num == 1:
        return 3
    if num % 2 != 0:
        return 1
    m = 1
    while m > 0:
        if not isprime((num * m) + 1):
            return m
        m += 1

num = int(input())
print(findInto(num))
