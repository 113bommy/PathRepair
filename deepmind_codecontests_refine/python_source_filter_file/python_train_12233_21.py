import math
n = int(input())

ans = 1
upper = int(math.sqrt(n))
for i in range(2, upper):
    if n % i == 0:
        ans *= i
        while n % i == 0:
            n /= i

ans *= n
print(int(ans))