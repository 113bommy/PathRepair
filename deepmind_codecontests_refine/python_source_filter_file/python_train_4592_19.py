import math


def is_prime(n):
    if n == 1:
        return False
    for i in range(2, round(math.sqrt(n))):
        if n % i == 0:
            return False
    return True


n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    if x - y > 1:
        print("NO")
    elif is_prime(x + y):
        print("YES")
    else:
        print("NO")