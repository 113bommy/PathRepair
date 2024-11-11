import math
def get_least_prime_div(a):
    for div in range(2, int(math.sqrt(a)) + 2):
        if a % div == 0:
            return div
    return 1

a = int(input())
total_steps = 0
if a % 2 == 0:
    total_steps += a // 2
    a = 0
if a % 2 != 0:
    div = get_least_prime_div(a)
    total_steps = 1
    a -= div
    total_steps += a // 2
    a = 0

print(total_steps)