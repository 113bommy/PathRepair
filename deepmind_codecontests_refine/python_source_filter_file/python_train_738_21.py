import math
n = int(input())
def smallest_prime_factor(n):
    for i in range(2, int(math.sqrt(n)), 2):
        if n%i == 0:
            return i
    return n
count = 0
if n%2!=0:
    n -= smallest_prime_factor(n)
    count += 1
print(count + n//2)