import math


def is_prime(n):
    if n <= 1:
        return 0
    for i in range(2,int(math.sqrt(n))+1):
        if n%i == 0:
            return i
    return n


for _ in range(int(input())):
    n,k = map(int,input().split())
    if n%2 == 1:
        val = is_prime(n)
        if val > 0:
            n+=val
        else:
            n+=3
        k -= 1

    n += 2*k
    print(n)

