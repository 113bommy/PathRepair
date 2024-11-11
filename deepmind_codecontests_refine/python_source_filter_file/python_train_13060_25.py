import math
def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            return False
    return True

n = int(input())
if n % 2 == 0:
   print(2, n-2)
else:
    sub = 2
    while is_prime(n - sub):
        sub += 2
    print(sub, n-sub)